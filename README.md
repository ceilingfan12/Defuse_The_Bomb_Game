# ENGR103FinalGame
# Author
Tyler Edmonds
# What Does This Code Do?
This code runs a defuse the bomb game on an Adafruit Circuit Playground Express.
This game has two levels: Long time mode (60 seconds) and short time mode (30 seconds).
The game functions by lighting up every NeoPixel with one of three random colors: red, green, or blue
Based on the color of each NeoPixel, the player will have to perform an action to the CPX to turn the pixel off
If all pixels are turned off before time expires, you win! Otherwise, you lose!
# Bomb Defusal Guide
See the attached files to access the instructions for defusing your randomized bomb!
# Inputs
Both buttons, slide switch, capacitance sensors, light sensor, and accelerometer
# Outputs
Serial monitor, speaker, and NeoPixels
# Rules
Players must read the Bomb Defusal manual to know what action to perform depending on the color of each NeoPixel. The slide switch will determine if the player has selected normal difficulty or hard difficulty. The game will begin with a message from the speaker that dictates what mode the player has selected and give them a countdown. Each NeoPixel has a random chance to light up as 3 different colors, and a different action must be performed for each color. The actions will be different for every NeoPixel. Once all of the NeoPixels have been turned off a happy noise will play, the NeoPixels will pulse green, and the speaker will deliver a victory message to the player. If the player does not manage to get all of the NeoPixels turned off in time, the speaker will play a sad noise and the pixels will flash red, and the speaker will deliver a loss message to the player. 
# Example
Pixel 0 lights up red. When I look at the Bomb Defusal Guide, I see that when Pixel 0 is red I need to push both buttons to turn it off. When I do this, the pixel turns off and I can move on to the next pixel
