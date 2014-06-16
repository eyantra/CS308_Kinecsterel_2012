2012 - CS308  Group 1 : Kinecsterel README
==================================================

Group Info:
------------
+   Priyank Parikh 	(09005006)
+   Nitant Vaidya 	(09005007)
+   Smit Patel	 	(09005002)
+   Lalit Swami 	(09005028)

Extension Of
------------

Our Project is not an actual extension of any previously done project. Although the Kinect has been used before to control the Firebird bot, we have not used code from any of the previous projects. All the code has been written by us (excluding sample code such as for programming the Kinect).

Project Description
-------------------

The main idea of this project is to provide an interface through which we can control the Firebird V bot using hand-gestures which are captured using a Microsoft Kinect device.
Basic Modules :-

+	The Kinect Module (C#) captures hand gestures which are mapped to functions to control the motion of the Firebird.
+	Esterel Module is used as an intermediary to convert movements to signals and use those signals to control the bot.
+	The Zigbee module is used to transmit these signals to the bot.

Our project extends to two users controlling two bots independently but using the same Kinect and PC. These two bots can then be made to play football against each other by two players using their hands to control them.

Through this project we introduce two major abstractions to the Kinect, Esterel and Firebird systems which can be used in future projects

+	__Kinect Gesture Recognition and Zigbee transmission__ : Future projects which involve bots receiving input from a Zigbee module could use our Kinect code in C# directly to map gestures to inputs. They need not define hand gestures or look into the details of the C# code or the working of the Kinect.

+	__Esterel Taking input from Zigbee__ : We have included an input signal in Esterel which reads Zigbee transmissions as input. Future projects requiring Zigbee transmission can use our Esterel modifications and then code in Esterel for their bot.


Technologies Used
-------------------

+   Embedded C
+   Xbee
+   Kinect   
+	Esterel

Installation Instructions
=========================

+ [Microsoft Visual Studio Express 2010](http://www.microsoft.com/visualstudio/en-us/products/2010-editions/visual-csharp-express)
+ [Microsoft Kinect SDK](http://www.microsoft.com/download/en/details.aspx?id=28782)
+ [Youtube tutorial](http://www.youtube.com/watch?v=G5ywya81jPw)

References
===========

+ [Kinect Skeleton Tracking Sample Code](http://channel9.msdn.com/Series/KinectSDKQuickstarts/Skeletal-Tracking-Fundamentals)
+ [Esterel Manual](http://www.cse.iitb.ac.in/~cs684/esterel/Programming_Firebird_Esterel_manual.pdf)
+ [Zigbee Manual](http://www.ladyada.net/make/xbee/configure.html)