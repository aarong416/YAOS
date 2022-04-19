#include <cmath/cmath.h>
#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/tty/tty_driver.h>

void dump(void* ptr, uint32_t count)
{
  char* memory_bytes = (char*) ptr;

  int width = 160;
  int bytes_per_row = floor(width / 4);
  int row_count = ceil((4 * count) / width);

  TtyDriver tty(true);

  // Stores the hex digit that was converted from an integer
  char s[3];

  for (int row_index = 0; row_index < ceil(count / bytes_per_row); row_index++) {
    char row_bytes[bytes_per_row];

    // Copy the contents of the current row of memory bytes into the
    // `row-bytes` array
    memcpy(row_bytes, memory_bytes + (row_index * bytes_per_row), bytes_per_row);

    /* Print all the hex digits for the current row first. After that, print
        the ASCII representation of the byte in memory */

    // Print each hex digit
    for (int i = 0; i < bytes_per_row; i++) {
      char byte = row_bytes[i];

      itoh((int) byte, s);

      tty.write(s);
      tty.writeChar(' ');
    }

    // Print the ASCII values for each byte in memory
    for (int i = 0; i < bytes_per_row; i++) {
      char byte = row_bytes[i];

      if (byte >= 32 && byte <= 127) {
        tty.writeChar(byte);
      } else {
        tty.writeChar('.');
      }
    }
  }
}

// void dump(void* ptr, uint32_t count)
// {
//   TtyDriver tty(true);

//   uint8_t* char_ptr = (uint8_t*) ptr;

//   uint32_t width = VgaHelper::getVgaWidth(); // The number of characters per row
//   uint32_t bytes_per_row =
//     floor(width / 4); // The total number of hex digits that can be printed on each row
//   uint32_t row_count = ceil((4 * count) / width); // The total number of rows to be printed

//   char bytes[bytes_per_row];       // The current's rows memory bytes
//   uint32_t current_byte_index = 0; // The index of the memory byte in the current rows
//   char s[3];

//   for (uint32_t i = 0; i < count; i++) {
//     uint8_t byte = char_ptr[i];
//     uint32_t row_index = floor(i / bytes_per_row);

//     bool is_hex_digit = ((current_byte_index != bytes_per_row) && (current_byte_index != count));
//     bool is_ascii_digit =
//       (current_byte_index == (bytes_per_row - 1)) || (current_byte_index == (count - 1));
//     bool is_last_row = i == (count - 1);

//     // Print the hex digits. TODO: should this be (bytes_per_row - 1)?
//     if (is_hex_digit) {
//       // Convert the integer value to hex and print it on the screen
//       itoh((int) byte, s);

//       tty.write(s);
//       tty.writeChar(' ');

//       bytes[current_byte_index++] = byte;

//       // If we are on the last row of bytes to print print spaces up until
//       // the start of the ASCII characters
//       if (is_last_row) {
//         is_ascii_digit = true;

//         // Calculate the number of bytes that haven't been printed
//         uint32_t spaces_to_print_count =
//           (row_count * (bytes_per_row * (CHARACTERS_PER_BYTE - 1)) % count);

//         if (spaces_to_print_count == (bytes_per_row * (CHARACTERS_PER_BYTE - 1))) {
//           spaces_to_print_count = 0;
//         }

//         // Print blank spaces so ASCII characters can be printed under the
//         // previous line's ASCII characters
//         for (uint32_t j = 0; j < spaces_to_print_count; j++) {
//           tty.writeChar('Y');
//         }
//       }
//     }

//     if (is_ascii_digit) {
//       // Calculate the number of bytes to print for the current row.
//       // If this is the last row, only print as many bytes as needed,
//       // otherwise print until the end of the row
//       uint32_t bytes_to_print_count =
//         is_last_row
//           ? bytes_per_row - ((row_count * (bytes_per_row * (CHARACTERS_PER_BYTE - 1)) % count) /
//                              (CHARACTERS_PER_BYTE - 1))
//           : bytes_per_row;

//       if (bytes_to_print_count == 0) {
//         bytes_to_print_count = bytes_per_row;
//       }

//       // All hex digits have been printed. Print their corresponding
//       // ASCII values in the right column
//       for (uint32_t j = 0; j < bytes_to_print_count; j++) {
//         uint8_t ascii_char = (char) bytes[j];

//         if (ascii_char >= 32 && ascii_char <= 127) {
//           tty.writeChar(ascii_char);
//         } else {
//           tty.writeChar('.');
//         }
//       }

//       current_byte_index = 0;
//     }
//   }
// }
