###CHANGELOG

**25 March 2015 - v0.6.0-alpha**
- Waitress now resets every time a new customer spawns
- Chef now has timer
- Smoke now renders when chef is cooking
- Added new customer images for popups
- Customer now spawns randomly instead of starting at the top left
- There is now a popup with the customer when they are served food
- There is now a food icon on the table when food is delivered to customer
- Fixed bug where chef timer would not start
- Fixed issue where chef timer is seen as microseconds
- Fixed a bug where waitress could take food from counter without taking orders
- Fixed a bug where smoke only renders for a few seconds
- Fixed a bug where smoke renders even after chef has finished cooking
- Fixed a bug where customer popup does not render on first spawn
- Fixed an issue where random customer spawning is not quite random
- A bug where customer popup bubbles failed to render every time a new customer spawns is now fixed

**17 March 2015 - v0.5.0-alpha**
- Added Timer class
- Added background to detect sprite position
- Added debug texts for timer
- Added debug texts for ordering mechanism
- Added pick up spot near counter
- Customers now spawn automatically
- Better code structure for storing customer spawning location
- Improved code readability
- Improved clock calculations
- Improved timer class
- Fixed makefile
- Fixed sprite position when debugging
- Fixed a bug where customer keeps on ordering, resulting in timer going on forever
- Fixed a bug where timer will increase even when customer did not order
- Fixed a bug where waitress can take food before order
- Fixed a bug where waitress does not need to be in pick up counter to pick up food

**12 March 2015 - v0.4.0-alpha**
- Added smoke image
- Waitress can now collide with objects
- There is now frames per second and capping
- Restructured and renamed some project files
- Rewrote main menu
- Rewrote sprite classes
- Rewrote level classes
- Improved button class
- Fixed a bug where button text is not rendered
- Fixed a bug where placement of text on a button is not centered
- Fixed a bug that caused debug text to not render
- Fixed a bug where FPS does not change in value
- Fixed a bug where button width bounds for mouse click is incorrect
- Fixed a bug which prevents sprite from moving

**4 March 2015 - v0.3.0-alpha**
- Rewrote debug mode
- Refactored button class
- Refactored text class
- Refactored background class

**19 February 2015(estimate) - v0.2.0-alpha**
- Added waitress sprite
- Added customer sprite
- Added tables
- Added counter for ordering
- Added chef sprite
- Added stove
- Added customer timer
- Added ability to click mouse and move character
- Added debug mode


**1 January 2015(estimate) - v0.1.0-alpha:**
- started development
