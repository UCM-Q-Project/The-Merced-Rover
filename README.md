#The [Q]uantiative Project
  * The [Q]uantitative Project is a project driven student organization at the University of California - Merced.
  * We take a interdisciplinary collaborative to our projects that build experience and allows for members from any background.
  * The Quantitiative part of our name relates to one of the overarching goals for all our projects - DATA.
    - All of our projects will produce to data which we will explore and analyze in the vein of Big Data analysis.

##The-Merced-Rover
 * The Merced Rover, codenamed Vanguard, is a project dedicated to constructing an autonomous rover, a la Google's self-driving car, from the ground up.
 * Various practices and skills applied:
 
  ###Arduino Programming
   * For programming movement, the Arduino microcontroller is our choice. The open source microcontroller is powerful enough for simple movement.
   * As of now, we are currently using the basic Arduino Uno board and a Parallax Arduino Shield bot kit to study different methods of autonomous movement and environmental response. The best methods we finds will be tested and applied to the Vanguard rover we build.
   * While a single Arduino is capable of controlling 4 wheels, it is not as ideal for the full scale Vanguard rover we are building. To increase functionality, we plan to use an Arduino for each individual wheel and have them controlled by a single Raspberry Pi. 
   * See below: Linux Programming - The Raspberry Pi

  ###CAD
   * Computer Aided Design allows for a visual approach that assists and expedites the design process.
   * Mechanical Engineers utilize Autodesk products, such as Inventor and Fusion, for the CADing process.
   * Rapid prototyping of parts that can be 3-D printed allows for a trial-error-adjustment approach.
   * For current part designs, see https://github.com/UCM-Q-Project/The-Merced-Rover/tree/master/Vangaurd/CAD

  ###Data Analysis and Machine Learning w/TensorFlow
   * We are collaborating with the Q Project's AI Research group whom will be implementing Artificial Intelligence to make the rover autonomous.
   * The AI Research division is currently researching the principles and applications of Machine Learning with Google's ML library TensorFlow.
   * More info can be found at The AI Research groups https://github.com/UCM-Q-Project/Data-Analysis--AI-Research
   
  ###Linux Programming - The Raspberry Pi
   * Arduino's are powerful in their own right, but the limits for their memory capacity and processing power falls short of what we need to control the Vanguard rover. So, to keep it within the realm of inexpensive Single Board Controllers, the Raspberry Pi is ideal.
   * The programming department are building a server on a Raspberry Pi to handle controlling the separate Arduino's and processing the input. This will allow for the autonomous behavior to be handled quicker and more efficiently.
