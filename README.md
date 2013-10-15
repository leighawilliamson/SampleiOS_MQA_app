# IBM Mobile Quality Assurance (MQA) iOS HelloWorld Example

This repository contains a working example of IBM Mobile Quality Assurance (MQA) in a very simple iOS app. To compile this example, you'll first need to install [Xcode](https://developer.apple.com/xcode/) from Apple. Next, follow these simple steps:

## Installation Steps

### 1. Create a free account with IBM Mobile Quality Assurance (MQA)

Get started by visiting the [MQA website](http://www.quality4mobile.com) and clicking "Sign Up". Follow the process to sign up for an account by entering your information and choosing a password.

### 2. Add a new application within Mobile Quality Assurance

If you just registered for a new account in step 1, you'll be taken to this step automatically. Alternatively, click the application drop down on the upper right-hand corner of the screen and choose "Add New".

Tell MQA the name of your application and the platform on which it runs (iOS, Android, or Windows Phone).

### 3. Copy the Application Key

Once you've added a new application in MQA, you'll be given a unique application key. You'll need to add this to your code in just a few minutes, so keep it readily available. (You can always retrieve this key later if you need it. It's available in the MQA web panel within the "Settings" menu on the left.)

### 4. Download or clone this git repository to your local computer

You can either clone this repository or download a zip file - whichever works for you.

### 5. Open the project in Xcode

Once you have downloaded the repository to your computer, navigate to the folder which contains the downloaded repository. Click on helloWorldMQAIntegration.xcodeproj to open the project in Xcode.

### 6. Open the application delegate file

Expand the project to see the included files and then expand the helloWorldMQAIntegration folder. Click on the utestAppDelegate.m file to open it.

### 7. Place your app key in the application delegate file

Locate a line that looks like:

<code>
	[APHLogger startNewSessionWithApplicationKey:@"Your-MQA-Application-Key-Goes-Here" apphanceMode:kAPHApphanceModeQA];
</code>

Replace the string *Your-MQA-Application-Key-Goes-Here* with the application key from Step 3.

### 8. Compile and run your app

Click the Run button on the upper left hand corner of the screen. If everything is setup correctly, this very basic application should compile and load in a simulator.

For more help, take a look at our online instructions for configuring [MQA with your iOS apps](http://help.quality4mobilehelp.com/library-installation/ios/).

## Logging Examples

MQA allows you to manually log events to the MQA server. This can be useful when you are debugging problems later because you can track custom defined activities from your application.

This sample application includes several examples of MQA's logging methods inside of utestAppDelegate.m, below the configuration steps listed above.

For more help with logging iOS events with MQA, visit our [help topics about logging](http://help.quality4mobilehelp.com/library-installation/ios/logging).

## Getting More Help

For more information about using IBM Mobile Quality Assurance, visit our online [help topics](http://help.quality4mobilehelp.com).  

If you have additional questions, email us at: [support@quality4mobile.com](mailto:support@quality4mobile.com)

## What is IBM Mobile Quality Assurance?

IBM Mobile Quality Assurance enables mobile developers to know precisely how their apps are working in the test lab and in the wild. A single library enables over-the-air app distribution, crash reports, in-app bug reports and user feedback. Now developers can discover in real time precisely what’s working – and what’s not – with their iOS, Android, Windows Phone, Kindle Fire and Nook apps. Learn more by visiting [quality4mobile.com](http://www.quality4mobile.com).


