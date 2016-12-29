#### Enable and disable styles one at a time.
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

#### Select multiple styles simultaniously.
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

#### Set the foreground (text) color.
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

#### Set text background color
```
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
```
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
#### Many ways to do the same thing.
```
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

#### Test all possible combinations of styles.
```
#include <iostream>
#include "csi.hpp"

int main(){
	/* Print "Hello World!" with every
	 * possible combination of styles. */
	for(int i = 0; i < 16; i++){
		std::cout << csi::style(
			(bool)(i / 1 % 2),
			(bool)(i / 2 % 2),
			(bool)(i / 4 % 2),
			(bool)(i / 8 % 2)
		);
		std::cout << "Hello World!"
		          << csi::style()
		          << std::endl;
	}
}
```
