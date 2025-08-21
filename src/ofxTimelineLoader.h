#pragma once
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <chrono>
#include <memory>
#include "ofxEasing.h"

namespace ofxTimelineLoader {

using Duration = std::chrono::milliseconds;

template<typename T>
struct Keyframe {
    Duration time;
    T value;
    ofxeasing::Function easing_function;
    ofxeasing::Type easing_type;
};

template<typename T>
class Track {
public:
    std::vector<Keyframe<T>> keyframes;

    T get_value(Duration time) const {
        if (keyframes.empty()) throw std::runtime_error("No keyframes");
        if (keyframes.size() == 1) return keyframes[0].value;

        // Find prev/next keyframes
        const Keyframe<T>* prev = nullptr;
        const Keyframe<T>* next = nullptr;
        for (const auto& kf : keyframes) {
            if (kf.time <= time) prev = &kf;
            if (kf.time > time) {
                next = &kf;
                break;
            }
        }
        if (!prev) return keyframes.front().value;
        if (!next) return keyframes.back().value;

        float t = float((time - prev->time).count());
        float d = float((next->time - prev->time).count());
        float b = float(prev->value);
        float c = float(next->value) - b;

        auto easing = ofxeasing::easing(prev->easing_function, prev->easing_type);
        return static_cast<T>(easing(t, b, c, d));
    }

    Duration get_duration() const {
        if (keyframes.empty()) return Duration(0);
        return keyframes.back().time;
    }
};

using MyVec2 = std::pair<float, float>;
using MyVec3 = std::tuple<float, float, float>;
using MyVec4 = std::tuple<float, float, float, float>;

using TrackVariant = std::variant<
    Track<bool>,
    Track<int>,
    Track<float>,
    Track<double>,
    Track<long long>,
    Track<MyVec2>,
    Track<MyVec3>,
    Track<MyVec4>
>;

class Timeline {
public:
    std::unordered_map<std::string, TrackVariant> tracks;

    Timeline() = default;

    template<typename T>
    void add(const std::string& name, const Track<T>& track) {
        tracks[name] = track;
    }

    template<typename T>
    Track<T>* get(const std::string& name) {
        auto it = tracks.find(name);
        if (it == tracks.end()) return nullptr;
        return std::get_if<Track<T>>(&it->second);
    }

    template<typename T>
    const Track<T>* get(const std::string& name) const {
        auto it = tracks.find(name);
        if (it == tracks.end()) return nullptr;
        return std::get_if<Track<T>>(&it->second);
    }

    template<typename T>
    T get_value(const std::string& name, Duration time) const {
        const Track<T>* track = get<T>(name);
        if (!track) throw std::runtime_error("Track not found");
        return track->get_value(time);
    }

    Duration get_max_duration() const {
        Duration max_dur(0);
        for (const auto& [_, variant] : tracks) {
            std::visit([&](auto&& track) {
                auto dur = track.get_duration();
                if (dur > max_dur) max_dur = dur;
            }, variant);
        }
        return max_dur;
    }
};

} // namespace ofxTimelineLoader