@owner antras saxena

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the screen dimensions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The -1 for OLED_RESET is used when sharing the Arduino reset pin.
#define OLED_RESET -1 
// You might need to change the address (0x3C or 0x3D are common)
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // Initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the display buffer
  display.clearDisplay();

  // Set up text properties
  display.setTextSize(1);      // Set text size (1 is smallest, 2 is double size, etc.)
  display.setTextColor(WHITE); // Set text color (WHITE on the default BLACK background)
  display.setCursor(0, 0);     // Set the starting position for the text (x, y)

  // Print text to the buffer
  display.println("Hello, Arduino!");
  display.println("OLED is working!");

  // Display the buffer on the screen
  display.display();
}

void loop() {
  // Your code for dynamic updates goes here
  // For example, reading a sensor and updating the display:

  /*
  // Clear the area you want to update (or use clearDisplay() for the whole screen)
  display.clearDisplay(); 
  display.setCursor(0, 0);
  display.println("New Value:");
  display.print(analogRead(A0)); // Print sensor reading

  display.display(); // Update the screen
  delay(100);
  */
}
