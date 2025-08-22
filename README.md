# ofxTimelineLoader

Data loader for ofxTimeline ( [original](https://github.com/YCAMInterlab/ofxTimeline) / [my fork](https://github.com/funatsufumiya/ofxTimeline) ) but also provide scriptable interface (kind of like [ofxKeyframeTween](https://github.com/nariakiiwatani/ofxKeyframeTween)). This addon works ***without ofxTimeline***. Using ofxTimeline as an timeline editor is an **option**.

(C++/oF port of [timeline_rs](https://github.com/funatsufumiya/timeline_rs))

Tested with oF v0.12.0.

### ofxTimeline as an timeline editor (option)

- For easy use of ofxTimeline as an editor, I'll recommend [loaf_timeline](https://github.com/funatsufumiya/loaf_timeline). It can be used like Love2D, even without oF.

## Dependencies

- ofxEasing: https://github.com/arturoc/ofxEasing/
    - NOTE: this makes problems on windows build now, so please use https://github.com/funatsufumiya/ofxEasing/ instead on windows.

## Examples

### [Easing Tester](./easing_tester/src/ofApp.cpp)

NOTE: This is just ofxEasing tester, but useful.

![screenshot_easing_tester](docs/screenshot_easing_tester.png)

### [Timeline Simple](./example_simple/src/ofApp.cpp)

Timeline constructing by script. 

If you want to use this addon as a standalone lib ***without ofxTimeline data***, this example would be helpful.

![screenshot_example_simple](docs/screenshot_example_simple.png)

```cpp
using namespace ofxTimelineLoader;
timeline = std::make_shared<Timeline>();

Track<float> tx;
tx.keyframes.push_back({std::chrono::milliseconds(0), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
tx.keyframes.push_back({std::chrono::milliseconds(1000), 1.0f, ofxeasing::Function::Cubic, ofxeasing::Type::Out});
tx.keyframes.push_back({std::chrono::milliseconds(2000), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
timeline->add<float>("x", tx);

// ...

x = timeline->get_value<float>("x", std::chrono::milliseconds((int)t_ms))
```

### [Timeline From XML](./example_xml/src/ofApp.cpp)

XML parsing example

![screenshot_example_simple](docs/screenshot_example_simple.png)

```cpp
std::string xml_x = R"(<keyframes>
<key>
    <easefunc>0</easefunc>
    <easetype>0</easetype>
    <time>00:00:00:524</time>
    <value>0.375000000</value>
</key>
<key>
    <easefunc>4</easefunc>
    <easetype>0</easetype>
    <time>00:00:02:123</time>
    <value>0.330175757</value>
</key>
</keyframes>)";

using namespace ofxTimelineLoader;
timeline = std::make_shared<Timeline>();
timeline->add<float>("x", track_from_xml<float>(xml_x));

// ...

x = timeline->get_value<float>("x", std::chrono::milliseconds((int)t_ms));
```

:writing_hand: NOTE: You can also parse JSON using `track_from_json(const ofJson& json)`.

## Dev notes

- :warning: Portation from [timeline_rs](https://github.com/funatsufumiya/timeline_rs) was mostly done with GitHub Copilot. Already tested, but use with care.

## License

WTFPL or 0BSD
