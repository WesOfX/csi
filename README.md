![Demo screenshot!](https://i.sli.mg/YabsGx.png)

## What is CSI?
Many terminals today support colors, styles, and other features only accessible with ANSI escape sequences. An ANSI escape sequence is a string which starts with the `\033` character a.k.a. an ANSI escape character. An ANSI escape character followed by a `[` character is called a control sequence introducer or CSI. A CSI needs to be suffixed with a character to determine what it does. Some CSI codes require parameters which are a number between the `[` and the suffix. Multiple parameters are separated with `;` characters. The following CSI code enables bold, italics, and underline: `\033[1;3;4m`

## Why is this library useful?
This library defines many methods for easily creating CSI strings without having to memorize the codes or the complicated syntax. Instead of having to remember `"\033[1m"` is enable bold and `"\033[21m"` is disable bold, you can just use `enable(style_code::bold)` and `disable(style_code::bold)`

## How to print text with style:
Two methods named `enable` and `disable` can be used to enable and disable any style. Both methods accept `style_code` values. `style_code` is an `enum` which defines 5 styles: `bold`, `italics`, `underline`, `strikethrough`, and `inverse`. `inverse` inverts the text color and the background color as-if the text is highlighted.
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
A method named `style` can be used to enable and disable all styles simultaneously. The method accepts 4 optional `bool`, all of which are `false` by default: `bool bold`, `bool italics`, `bool underlined`, and `bool strikethrough`.
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
## How to print colored text:
Two methods named `foreground` and `background` can be used to set the text color and the background color respectively. Both methods accept `color_code` values. `color_code` is an `enum` which defines 9 colors: `none`, `black`, `red`, `green`, `yellow`, `blue`, `magenta`, `cyan`, and `white`. `none` is the terminal's default color.
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
A method named `color` can be used to set the text color and the background color simultaneously. The method accepts 2 optional `color_code`, both of which are `none` by default, and an optional `bool` which is `false` by default: `color_code foreground`, `color_code background`, and `bool inverse`.
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
## How to move the cursor:
Seven methods are defined for moving the cursor. They are `cursor_up`, `cursor_down`, `cursor_forward`, `cursor_back`, `cursor_next_line`, `cursor_previous_line`, and `cursor_position`. `cursor_position` accepts two parameters: `row` and `column`, both 1 by default (top-left corner) while the other methods accept a single parameter, also 1 by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the cursor position to the second column of
	   the second row, print "Hello World!", then print
	   a new line. */
	std:: cout << csi::cursor_position(2, 2)
	           << "Hello World!"
	           << std::endl;
}
```
## How to erase the display:
Not only can the display be erased, lines can be erased and even portions of lines can be erased. Two methods named `erase_display` and `erase_line` are defined and they both accept an `erase_mode` value. `erase_mode` is an `enum` which defines three modes: `to_end`, `to_beginning`, and `all`. `to_end` erases from the cursor to the end of the line/display. `to_beginning` erases from the cursor to the beginning of the line/display. `all` erases the entire line/display. For both methods, `erase_mode` is `all` by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Erase the display and print "Hello World!",
	   then print a new line */
	std:: cout << csi::erase_display()
	           << "Hello World!"
	           << std::endl;
}
```
