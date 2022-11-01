#include <cmath/cmath.h>
#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/tty/tty_driver.h>

/**
 * Prints spaces for the current row so that the ASCII characters for the last
 * row can be printed below the ASCII characters for the previous row
 *
 * @param bytes_per_row The number of hex digits printed per row
 * @param count         The total number of bytes to dump
 */
void print_spaces_until_ascii(uint32_t bytes_per_row, uint32_t count)
{
  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  uint32_t spaces_count = (bytes_per_row - (count % bytes_per_row)) * (CHARACTERS_PER_BYTE - 1);

  if (spaces_count == bytes_per_row) {
    spaces_count = 0;
  }

  for (uint32_t i = 0; i < spaces_count; i++) {
    tty->writeChar(' ');
  }
}

// Pruint32_t hex digits
void print_hex(char row_bytes[], uint32_t bytes_to_print_count)
{
  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  // Stores the hex digit that was converted from an integer
  char s[3];

  // Convert each byte of memory to a hex digit, and the pruint32_t it
  for (uint32_t i = 0; i < bytes_to_print_count; i++) {
    char byte = row_bytes[i];

    itoh((int) byte, s);

    tty->writeChar(s[0]); // TODO: should be able to do write(s): itoa not working properly
    tty->writeChar(s[1]);
    tty->writeChar(' ');
  }
}

/**
 * Prints the ASCII representation of each byte in memory. If the byte
 * is a printable character (32 -> 127 in decimal), pruint32_t it. Otherwise, pruint32_t a
 * '.' if it isn't.
 *
 * @param row_bytes: The bytes to pruint32_t for the current row
 * @param count:     The number of ASCII characters to print
 */
void print_ascii(char row_bytes[], uint32_t count)
{
  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  for (uint32_t i = 0; i < count; i++) {
    unsigned char byte = row_bytes[i];

    if (byte >= 32 && byte <= 127) {
      tty->writeChar(byte);
    } else {
      tty->writeChar('.');
    }
  }
}

/**
 * Dumps the contents of memory for the current row.
 *
 * The first column on the left printd the hexadecimals digits of the contents
 * of memory, and the column on the right prints the ASCII representation of the
 * hex digits.
 *
 * @param row_bytes     The bytes of memory for the current row
 * @param bytes_per_row The number of hex digits that are printed on each row
 * @param count         The total number of bytes in memory to dump
 * @param is_last_row   True if this is the last row, false otherwise
 */
void print_row(char row_bytes[], uint32_t bytes_per_row, uint32_t count, bool is_last_row)
{
  // Determine the number of bytes to print. If this is the last row, only
  // print the last remaining bytes
  uint32_t bytes_to_print_count = is_last_row ? (count % bytes_per_row) : bytes_per_row;

  // Print the hex digits for each byte in the current row
  print_hex(row_bytes, bytes_to_print_count);

  // If this is the last row, pruint32_t blank spaces until we can pruint32_t ASCII
  // characters in the ASCII characters column
  if (is_last_row) {
    print_spaces_until_ascii(bytes_per_row, count);
  }

  // Pruint32_t the ASCII representation of the bytes in memory for the current row
  print_ascii(row_bytes, bytes_to_print_count);

  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  tty->writeLine("");
}

/**
 * Dump the contents of memory from `ptr` for `count` bytes.
 *
 * Hexadecimal values on printed on the left, and their corresponding
 * ASCII characters are printed on the right.
 *
 * @param ptr   The address to start dumping memory from
 * @param count The number of bytes of memory to dump
 */
void dump(void* ptr, uint32_t count)
{
  /**
   * memory_bytes:  the bytes in memory to dump
   * width:         the total number of printable characters per line
   * bytes_per_row: The total number of hex digits printable per row
   * row_count:     The number of rows
   */
  char* memory_bytes = (char*) ptr;
  uint32_t width = VgaHelper::getVgaWidth();
  uint32_t bytes_per_row = floor(width / CHARACTERS_PER_BYTE);
  uint32_t row_count = ceil((CHARACTERS_PER_BYTE * count) / width);

  // Iterate over each byte in memory, treating the bytes in memory as a
  // two dimensional array of rows and columns instead of a contigous block
  // of memory. This allows for easily printing all the hex digits first, then
  // printing all the ASCII characters after.
  for (uint32_t row_index = 0; row_index < row_count; row_index++) {
    /**
     * row_bytes:   The bytes displayed on the current row
     * is_last_row: True if the current row is the last row, false otherwise
     * index:       The index into the memory where the bytes for the current
     *              row starts
     */
    char row_bytes[bytes_per_row];
    bool is_last_row = (row_index == (row_count - 1));
    void* index = memory_bytes + (row_index * bytes_per_row);

    // Copy the contents of the current row of memory bytes into an array
    memcpy(row_bytes, index, bytes_per_row);

    // Dump the contents of memory for the current row
    print_row(row_bytes, bytes_per_row, count, is_last_row);
  }
}
