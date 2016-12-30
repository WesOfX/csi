Many terminals today support colors, styles, and many other features only accessible with the use of ANSI escape sequences. An ANSI escape sequence is a string which starts with an ANSI escape character `'\033'`. An ANSI escape character followed by an opening square bracket character `"\033["` is called a control sequence introducer or CSI. Following a CSI, a suffix character determins the function. e.g. `"\033[C"` moves the cursor forward 1 column and `"\033[E"` moves the cursor to the next line. Before the suffix character, a number can be used as a parameter. e.g. `"\033[7C"` moves the cursor forward 7 columns.

This library defines many methods in the `csi` namespace for easily creating ANSI escape sequence strings without having to memorize their syntax or their codes. Instead of having to remember `"\033[1m"` is enable bold and `"\033[21m"` is disable bold, you can just use `csi::enable(csi::style_code::bold)` and `csi::disable(csi::style_code::bold)`

#### Enable and disable styles one at a time.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Enable bold, print "Hello World!",
	 * disable bold, then print a newline. */
	std::cout << csi::enable(csi::style_code::bold)
	          << "Hello World!"
	          << csi::disable(csi::style_code::bold)
	          << std::endl;
}
```

#### Select multiple styles simultaniously.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	// Enable italics and strikethrough
	std::cout << csi::style(
		false, // Bold
		true, // Italics
		false, // Underlined
		true // Strikethrough
	);

	/* Print "Hello World!", disable all
	 * styles, then print a new line. */
	std::cout << "Hello World!"
	          << csi::style()
	          << std::endl;
}
```

#### Set the foreground (text) color.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to yellow, print "Hello World!",
	 * set the text color to default, then print a new line */
	std::cout << csi::foreground(csi::color_code::yellow)
	          << "Hello World!"
	          << csi::foreground()
	          << std::endl;
}
```

#### Set text background color
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the background color to blue, print
	 * "Hello World!", set the text color to default,
	 * then print a new line */
	std::cout << csi::background(csi::color_code::blue)
	          << "Hello World!"
	          << csi::background()
	          << std::endl;
}
```

#### Set the foreground color and the background color simultaniously.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to cyan,
	 * the background color to magenta. */
	std::cout << csi::color(
		csi::color_code::cyan, // Text color
		csi::color_code::magenta, // Background color
	);

	/* Print "Hello World!", set
	 * the colors to default, then
	 * print a new line. */
	std::cout << "Hello World!"
	          << csi::color()
	          << std::endl;
}
```

#### Erase the display and move the cursor.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Erase display, set the cursor position
	 * to the second column of the second row,
	 * print "Hello World!", then print a new
	 * line. */
	std:: cout << csi::erase_display()
	           << csi::cursor_position(2, 2)
	           << "Hello World!"
	           << std::endl;
}
```
#### Many ways to do the same thing.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Enable bold text, print "Hello World",
	 * disable bold text, then print a new line. */
	std::cout << csi::enable(csi::style_code::bold) // "\033[1m"
	          << "Hello World!"
	          << csi::disable(csi::style_code::bold) // "\033[21m"
	          << std::endl;

	// This is equivilent
	std::cout << csi::select_graphic_rendition(1) // "\033[1m"
	          << "Hello World!"
	          << csi::select_graphic_rendition(21) // "\033[21m"
	          << std::endl;

	// This is equivilent
	std::cout << "\033[1m"
	          << "Hello World!"
	          << "\033[21m"
	          << std::endl;

	// This is NOT equivilent.
	/* Enable bold and disable italics, underlined,
	 * and strikethrough, print "Hello World!", disable
	 * all styles, then print a new line. */
	std::cout << csi::style(true) // "\033[1;23;24;29m"
	          << "Hello World!"
	          << csi::style() // "\033[21;23;24;29m"
	          << std::endl;
}
```

#### Test all possible combinations of styles and colors
```cpp
#include <iostream>
#include "csi.hpp"

#include <array>
#include <math.h>

int main(){
	/* Print "Aa" with every possible combination of
	 * style and foreground and background colors inverted
	 * and not inverted. */
	constexpr size_t color_count = 8;
	constexpr std::array<csi::color_code, color_count> all_colors = {
		{
			csi::color_code::black,
			csi::color_code::red,
			csi::color_code::green,
			csi::color_code::yellow,
			csi::color_code::blue,
			csi::color_code::magenta,
			csi::color_code::cyan,
			csi::color_code::white,
		}
	};
	for(size_t i = 0; i < pow(color_count, 2); i++){
		std::cout << csi::color(
			all_colors[i % color_count],
			all_colors[i / color_count % color_count]
		);
		constexpr size_t style_count = 4;
		for(size_t j = 0; j < pow(2, style_count); j++){
			std::cout << csi::style(
				(bool)(j / 1 % 2),
				(bool)(j / 2 % 2),
				(bool)(j / 4 % 2),
				(bool)(j / 8 % 2)
			);
			std::cout << "Aa"
			          << csi::enable(csi::style_code::inverse)
			          << "Aa"
			          << csi::disable(csi::style_code::inverse);
		}
		std::cout << csi::color() << std::endl;
	}
}
```
[PNG screenshot of the output of the code above in a Gnome Terminal using the Tango color scheme.](https://i.sli.mg/4wnVC5.png)
