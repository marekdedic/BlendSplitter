#Changelog

## [3.1.0] - 2016-12-01 - CMake
 - Using CMake
 - SwitchingWidget and BlendSplitter can take RegistryItem as parameter

## [3.0.0] - 2016-10-03 - Public API
 - Defined a public API: https://genabitu.github.io/BlendSplitter/
 - Documented everything using Doxygen
 - Using Semantic versioning 2.0.0: http://semver.org/
 - Tighter access control for the public API
 - Explicit constructors
 - All settings as static BlendSplitter members
 - Default Expander image included in library
 - Destructors for layouts
 - Removed iostream dependency - using Qt io
 - SwitchingBar::addMenu() now returns void
 - WidgetRegistry::setDefault() checks the item

## [2.1.0] - 2016-06-12 - Header structure
 - Added sensible header file structure, nothing changed regarding functionality.

## [2.0.0] - 2016-05-06 - Added SwitchingWidget
 - Added a SwitchingWidget, which lets the user switch widgets on the fly. It provides a Menu/Widget bar, a combo switcher. The widgets are pulled from WidgetRegistry.
 - Debian package: https://mentors.debian.net/package/libblendsplitter2
 - Ubuntu PPA: ppa:genabitu/libblendsplitter2

## [1.0.0] - 2016-03-25 - Initial release
 - The library as I thought is ready for use, no menubars or widget pools (things yet to be implemented), just the Splitter, working.

