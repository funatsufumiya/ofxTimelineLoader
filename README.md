# ofxTimelineLoader

Loader for ofxTimeline ( [original](https://github.com/YCAMInterlab/ofxTimeline) / [my fork](https://github.com/funatsufumiya/ofxTimeline) ) but also provide scriptable interface

(C++/oF port of [timeline_rs](https://github.com/funatsufumiya/timeline_rs))

### NOTE: ofxTimeline as an timeline editor

- For easy use of ofxTimeline as an editor, I'll recommend [loaf_timeline](https://github.com/funatsufumiya/loaf_timeline). It can be used like Love2D, even without oF.

## Dependencies

- ofxEasing: https://github.com/arturoc/ofxEasing/
    - NOTE: this makes problems on windows build, so please use https://github.com/funatsufumiya/ofxEasing/ instead on windows.

## Examples

### [Easing Tester](./easing_tester/)

NOTE: This is just ofxEasing tester, but useful.

![screenshot_easing_tester](docs/screenshot_easing_tester.png)

### [Timeline Simple](./example_simple/)

Timeline constructing by script. 

If you want to use this addon as a standalone lib without ofxTimeline data, this example would be helpful.

![screenshot_example_simple](docs/screenshot_example_simple.png)

### [Timeline From XML](./example_xml/)

XML parsing example

![screenshot_example_simple](docs/screenshot_example_simple.png)

## Dev notes

- Portation from [timeline_rs](https://github.com/funatsufumiya/timeline_rs) was mostly done with GitHub Copilot. Already tested, but use with care.

## License

WTFPL or 0BSD
