![Demo screenshot!](https://i.sli.mg/nDPouC.png)

## What is CSI?
Many terminals today support colors, styles, and other features only accessible with ANSI escape sequences. An ANSI escape sequence is a string which starts with the `\033` character a.k.a. an ANSI escape character. An ANSI escape character followed by a `[` character is called a control sequence introducer or CSI. A CSI needs to be suffixed with a character to determine what it does. Some CSI codes require parameters which are a number between the `[` and the suffix. Multiple parameters are separated with `;` characters. The following CSI code enables bold, italics, and underline: `\033[1;3;4m`

## Why this library is useful
This library defines many methods for easily creating CSI strings without having to memorize the codes or the complicated syntax. Instead of having to remember `"\033[1m"` is enable bold and `"\033[21m"` is disable bold, you can just use `enable(style_code::bold)` and `disable(style_code::bold)`

## Code Examples
Enable and disable styles one at a time.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Enable bold, print "Hello World!",
	   disable bold, then print a newline. */
	std::cout << csi::enable(csi::style_code::bold)
	          << "Hello World!"
	          << csi::disable(csi::style_code::bold)
	          << std::endl;
}
```
Select multiple styles simultaneously.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	// Enable italics and strikethrough
	std::cout << csi::style(
		false, // Bold
		true,  // Italics
		false, // Underlined
		true   // Strikethrough
	);

	/* Print "Hello World!", disable all
	   styles, then print a new line. */
	std::cout << "Hello World!"
	          << csi::style()
	          << std::endl;
}
```
Set the foreground and background color separately. (Text color)
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to yellow, print "Hello World!",
	   set the text color to default, then print a new line */
	std::cout << csi::foreground(csi::color_code::yellow)
	          << "Hello World!"
	          << csi::foreground()
	          << std::endl;
		  
	/* Set the background color to blue, print "Hello World!", 
	 * set the background color to default, then print a new line */
	std::cout << csi::background(csi::color_code::blue)
	          << "Hello World!"
	          << csi::background()
	          << std::endl;
}
```
Set the foreground color and the background color simultaneously.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to cyan,
	   the background color to magenta. */
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
Erase the display and move the cursor.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Erase display, set the cursor position
	   to the second column of the second row,
	   print "Hello World!", then print a new
	   line. */
	std:: cout << csi::erase_display()
	           << csi::cursor_position(2, 2)
	           << "Hello World!"
	           << std::endl;
}
```
