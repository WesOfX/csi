#### How to enable and disable styles one at a time
```
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

#### How to select multiple styles simultaniously
```
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

#### How to set text color
```
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

#### How to set text background color
```
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text background color to blue, print
	 * "Hello World!", set the text color to default,
	 * then print a new line */
	std::cout << csi::background(csi::color_code::blue)
	          << "Hello World!"
	          << csi::background()
	          << std::endl;
}
```

#### How to set the text color and the background color simultaniously
Optionally, the text color and background color can be inverted
```
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to cyan,
	 * the background color to magenta,
	 * but invert the text color and
	 * the background color. */
	std::cout << csi::color(
		csi::color_code::cyan, // Text color
		csi::color_code::magenta, // Background color
		true // Inverted colors
	);

	/* Print "Hello World!", set
	 * the colors to default, then
	 * print a new line. */
	std::cout << "Hello World!"
	          << csi::color()
	          << std::endl;
}
```

#### How to erase the display and move the cursor
```
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
