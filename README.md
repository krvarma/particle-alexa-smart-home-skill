Alexa Smart Home Skill Kit for Particle Devices
-----------------------------------------------

As you all know Amazon recently release Alexa Smart Home Skill API. Amazon Alexa provides built-in smart home capabilities like turning on/off lights, control air conditioners, etc... Developer can use Alexa Smart Home Skill API to extend the smart home capabilities of Alexa. For Smart Home Skill APIs you don't need to create a custom voice interaction models. Alexa has built-in standard interaction models for smart home, like:

Alexa, turn on lights
Alexa, set light to 50 percentage,
Alexa, set the temperature to 24
.
.
.

Previously Alexa works with a limited number of smart home devices like Philips Hue, etc... But with this newly introduced Smart Home Skill APIs we can integrate devices that are not supported by Alexa by default.

Recently I started working on integrating Particle Device and Smart Home Skill API. I is fairly simple to create a Smart Home Skill if you already know how to create a Alexa Skill. I have created a Skill before using Particle Photon.

The only issue was to figure out how to integrate OAuth2 login with Particle. Smart Home Skill API needs a server that supports OAuth2 Authorization Code Flow. With the help awesome peoples like ... I was able to integrate OAuth2 with Particle.

In this project I emulate two lights that can be turned on/off using Alexa Voice Interaction. For the purpose of this demo, I have connected two LEDs to pins A4 and A5. 

Describing how to create a Smart Home Skill is not in the scope of this article. For a detailed explanation of how to create a Smart Home Skill, please refer to [this link](https://developer.amazon.com/public/solutions/alexa/alexa-skills-kit/docs/steps-to-create-a-smart-home-skill).

In order create Smart Home Skill, Amazon requires a server that supports OAuth2 Authoriation Code Flow and Cloud APIs to control devices. At time writing this article, Amazon does not supports devices without Cloud APIs. Also as of now Alexa Smart Home Skill API supports only two types of devices, lights and air conditioners. But you can hack it to work with other type of devices also.

By default the Skill you creates will be private to your account. After testing you can submit to Amazon for review and if it is approved you cna make open for public. After the Skill is created, you have to enable it using the Alexa application. To enable it select **Skills** from side menu and find and enable your skill. Then start discovering devices using the **Smart Home** menu item. This will ask you to logon to the cloud using the OAuth2. Once you successfully authenticated the access token will be saved and it will be passed on to your Lambda function.

When the device discovery is performed, the Smart Home Skill API will call the Lambda function attached to the Skill with `Alexa.ConnectedHome.Discovery` event. When this event is recevied your Lambda function will return the device list. When the user controls these devices using voice input, the Lambda function attached to the Skill will be called with `Alexa.ConnectedHome.Control` event and you can call the Cloud APIs to control the device. For a more detailed explanation of how to create Skill and Lambda function refer to [this link](https://developer.amazon.com/public/solutions/alexa/alexa-skills-kit/docs/steps-to-create-a-smart-home-skill).

Some of the screenshots of the Skill Information and Lambda function is given below:

*Skill Information*
![Skill Information](https://raw.githubusercontent.com/krvarma/particle-alexa-smart-home-skill/master/images/Skill-Information.png)

*Skill Configuration*
![Skill Configuration](https://raw.githubusercontent.com/krvarma/particle-alexa-smart-home-skill/master/images/Skill-Configuration.png)

*Lambda Function Eventsource*
![enter image description here](https://raw.githubusercontent.com/krvarma/particle-alexa-smart-home-skill/master/images/Lambda-Event-Source.png)

**Sample Application**

The sample has tow components, Alexa Smart Home Skill and Particle Firmware.

***Particle Firmare***

The Particle firmware emulates two lights using LEDs. These LEDs are attached to A4 and A5 pins. The firmware has functions to turn on/off the LEDs and to set the brightness of the LEDs.

![Schematics](https://raw.githubusercontent.com/krvarma/particle-alexa-smart-home-skill/master/images/schematics.png)

***Alexa Smart Home Skill***

Alexa Smart Home Skill has Skill information and the Lambda function. The Skill information contains the details about the skill such as Skill name, OAuth details, etc... The Lambda function responds to the Smart Home Skill Events.

User can interact with skill using voice input such as:

*Alexa, turn on bedroom light*

*Alexa, turn off bedroom light*

*Alexa, turn on kitchen light*

*Alexa, turn off kitchen light*

*Alexa, set kitchen light to 50 percentage*

**Demo Video**

*Enabling the Smart Home Skill*

[https://www.youtube.com/watch?v=0rEBe_ZNBTk](https://www.youtube.com/watch?v=0rEBe_ZNBTk)

*Interacting with the Skill*

[https://www.youtube.com/watch?v=9h0kfl14Tqw](https://www.youtube.com/watch?v=9h0kfl14Tqw)