###CHANGELOG

**15 December 2015 - v1.0.1**
- Fixed compilation error

**25 April 2015 - v1.0.0**
- Removed redundant code in menu system
- Removed unnecessary adding of customer time
- Refactored timer code
- Fixed bug with adding time

**19 April 2015 - v0.11.0-beta**
- Customer failure now increases when waitress did not serve customer within allocated time
- Improved customer background detection
- Improved checking for food order
- Improved customer popup rendering
- Cleaned up game compilation
- Collision with walking customers now fixed
- Fixed alignment issues
- Fixed a bug where waitress would spawn before serving customers
- Fixed a bug with background detection
- Fixed a bug where customer failure number will increment when customer is spawning
- Standing at the food pickup point which simulates serving food to customer is now fixed
- Customer failure leading to neutral background now fixed
- Fixed issue involving logic bugs with regards to comparison between customer being successfully served and customer who failed to be served

**12 April 2015 - v0.10.0-beta**
- Added ability to read from text files when loading game
- Refactored some functions in user interfaces classes
- Fixed a bug where texts are not rendered to screen

**6 April 2015 - v0.9.0-alpha**
- Added a mode select menu screen
- Added normal and practice mode
- A new how to play screen
- Added a few things to enhance gameplay
- Added a new image class to facilitate GUI in help screen
- Customer failure mechanism works now  when waitress collides with walking customer
- You can now return to main menu or retry when the game is over

**3 April 2015 - v0.8.0-alpha**
- Added a back button in the level to go back to main menu
- Waitress can now take orders from all four locations
- Added a debug toggle in settings to enable easy debugging
- Added a control toggle in settings for players to choose between keyboard and mouse or trackpad control
- Increased the screen size for better gameplay and collision detection
- Added two walking customers for better gameplay
- Fixed a bug where walking customers would disappear before waitress collides with it
- Fixed a bug where debug and control settings will always be in the same state
- Fixed a bug where chef will cook before waitress has picked from menu
- Fixed a bug preventing waitress from taking orders from multiple locations

**30 March 2015 - v0.7.0-alpha**
- Food and drink items added
- New menu system
- New customer ordering mechanism
- New customer timer mechanism
- Added gameplay mechanisms to ensure food picked by waitress is correct
- Added debug flags for waitress picking food
- Added debug flags for food being picked
- Added customer popup when the order is incorrect
- Added on screen debug flags for customer spawn position
- Added on screen debug flags for customer order
- Added indicators for customer successful orders and fail orders
- Added level timer
- Added three game over screen images, one for success, one for fail, another for neutral, where there is no wins and no loss
- Added mechanism to tell for successful or fail game for user
- Added how to play screen
- Added conditional macros to switch between debug statements
- Fixed a bug that caused customers to spawn after ordering
- Fixed a logic bug where there is conflict between the food and incorrect order customer popup
- Fixed a bug that caused a second unresponsive window to get created after the game has finished gameplay
- Fixed a bug that caused the game over screen to always start with the same screen due to a memory release

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
