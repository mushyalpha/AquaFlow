00:00:00
Speaker 1
So, record on this computer, so today I'm talking about GUIs and graphical user interfaces a bit, and then, and then depending on the time we have, also on...
00:00:16
Speaker 1
transmission transmission about this here.
00:00:18
Speaker 1
Quick questions about workflow.
00:00:21
Speaker 1
Is this actually a personal message here?
00:00:24
Speaker 1
So questions like that, I'm not answering here in this lecture.
00:00:29
Speaker 1
So questions like that can be answered in the lab on Wednesday.
00:00:36
Speaker 1
So we are not going into nitty-gritty questions here or something like that.
00:00:41
Speaker 1
So we had just the lab yesterday, you know, you had
00:00:46
Speaker 1
question, you could ask questions about that there.
00:00:49
Speaker 1
So this lecture is about lecture and we're talking about lecture, lecture material and not just private discussions about something like that.
00:00:57
Speaker 1
And so, and also about these policy issues there.
00:01:02
Speaker 1
High-level discussions you can also do with Chong Feng regarding these things.
00:01:07
Speaker 1
Yeah, so let's stick to the coding here.
00:01:11
Speaker 1
So this lecture is all about coding stuff.
00:01:14
Speaker 1
So, QT, so we need to talk about graphical user interfaces and under Unix, the standard GY is QT.
00:01:26
Speaker 1
So, there are obviously other likes like TCLTK and also you could also code in raw stuff, but a lot of people are, I would say, most people using QT for the coding.
00:01:41
Speaker 1
So what is QT?
00:01:43
Speaker 1
So QT is a cross-platform environment.
00:01:47
Speaker 1
It's not just for Linux.
00:01:49
Speaker 1
You can also code under Windows and Mac.
00:01:51
Speaker 1
So if you have nothing which is hardware related, then you can basically cross-compile that.
00:01:59
Speaker 1
So I've compiled QT for also for Windows and Mac.
00:02:04
Speaker 1
So the great thing is
00:02:06
Speaker 1
That, if you're developing a Windows environment, it will work on different platforms, and that's the reason why it became very, very popular.
00:02:15
Speaker 1
So, QT has been around for over 20 years, and it's evolving and evolving, and which is quite nice to have something which is like a constant and is there.
00:02:28
Speaker 1
So, once you learn it,
00:02:30
Speaker 1
It's very useful, for all different kinds of applications.
00:02:34
Speaker 1
You can even write QT for your mobile phone.
00:02:37
Speaker 1
So therefore it's very flexible.
00:02:40
Speaker 1
So I've, as I said, I've written for Linux, Windows, and Mac.
00:02:44
Speaker 1
And so even on a Mac, it's pretty easy to use.
00:02:48
Speaker 1
Okay, so how does it work in QT?
00:02:51
Speaker 1
So, in QT, everything is a widget, so that's a that's a lingo, so how they how they talk about this, so widget widget is any graphical element, so widget could be it could be a button, so it could be, as you see, this reset button here, widget #2, it's it can be this thermometer here, for example, or just plotting some graphical stuff here, yeah, so
00:03:20
Speaker 1
And the great thing is you can also configure, create your own widgets.
00:03:25
Speaker 1
So if you have some other crazy stuff like whatever, like a speed meter or some animation or something like that, you can also write your own widget and put this into this environment.
00:03:35
Speaker 1
So QT, someone like takes care of the layout of this and also then about how it's displayed.
00:03:44
Speaker 1
And so
00:03:46
Speaker 1
So, very flexible environment, and so, and the other great thing is also on a Linux QT, there are packages, so we don't need to need to compile anything.
00:03:55
Speaker 1
You're just doing app install and you have the QT environment there.
00:04:00
Speaker 1
So, when the so how does it how does it work with layout?
00:04:06
Speaker 1
So, in QT, so in QT everything is so these widgets are classes.
00:04:13
Speaker 1
So, this button here is a class called QButton, and you are creating basically with a new operator here, that's the instance of this button here.
00:04:25
Speaker 1
So, in this case, here is a reset button, and then here you are creating another widget here called here thermometer.
00:04:35
Speaker 1
and then you're creating another widget plot.
00:04:38
Speaker 1
Yeah, so we see here these are instances of these of these classes here they're already predefined, or you can define your own own ones here.
00:04:48
Speaker 1
So, now the question is, basically, how do we how do we arrange them in the window?
00:04:53
Speaker 1
So, we've got now, so the you know the reset button, we've got the thermometer and the plot, and we would like to have
00:05:02
Speaker 1
to have the reset button and the thermometer in a vertical arrangement.
00:05:08
Speaker 1
So we want to have these two here in this vertical arrangement here.
00:05:14
Speaker 1
So reset button above the thermometer.
00:05:17
Speaker 1
And the idea is very simple.
00:05:20
Speaker 1
Again, we take another class.
00:05:22
Speaker 1
So this class is called QVBoxLayout.
00:05:25
Speaker 1
So V for vertical.
00:05:28
Speaker 1
And so we are creating instance of that.
00:05:32
Speaker 1
So that's so this black box here is our is our V box layout and then and then we are adding widgets these two widgets to it.
00:05:42
Speaker 1
So you see here VV layout here the instance and this has a has a method called add widget and so we're adding the button here and then we're adding the widget thermo here.
00:05:54
Speaker 1
and then just create this layout here.
00:05:57
Speaker 1
So we're putting this essentially into a vertical box.
00:06:02
Speaker 1
So the whole thing, that's the idea behind that.
00:06:07
Speaker 1
So now we have here this sine wave plot here on the right.
00:06:13
Speaker 1
So the sine wave plot we would like to have to the right of this vertical layout here.
00:06:19
Speaker 1
So what do we do?
00:06:20
Speaker 1
So we are creating a horizontal layout now.
00:06:22
Speaker 1
So we're creating a box
00:06:24
Speaker 1
of the whole thing here.
00:06:27
Speaker 1
So QH box means horizontal layout.
00:06:30
Speaker 1
And then we are adding the vertical layout in this box.
00:06:34
Speaker 1
So we're creating, so we're putting this vertical box into this horizontal box here, add layout.
00:06:41
Speaker 1
And then we are adding this plot here to it, next to it, to the right.
00:06:47
Speaker 1
And then with that, we have created the whole box.
00:06:50
Speaker 1
And then once you have finished this,
00:06:53
Speaker 1
We have, we're just adding adding this layout here with the just the overall QT method here, set layout, and putting the whole layout in it.
00:07:04
Speaker 1
So, you see the general ideas of QT is creating boxes within boxes, if you're creating layouts.
00:07:12
Speaker 1
So, and the interesting thing is, you know, when you're looking at other GUIs out there, especially for mobile phone development,
00:07:22
Speaker 1
So, Google and Android, for example, they had a, and Apple also, they had for the iPhones, they had initially XML documents describing how the different widgets are placed on the phone screen or on the screen in general.
00:07:41
Speaker 1
So, basically, both companies also know they have abandoned these description files.
00:07:48
Speaker 1
and also using directly, the coding language to define the layout.
00:07:53
Speaker 1
So it's interesting, there's somewhat like a evolution in the direction that layouts are just also defined in code.
00:08:01
Speaker 1
So if you're looking in the modern development of the Android system,
00:08:12
Speaker 1
So they are basically layout is defined in Kotlin.
00:08:15
Speaker 1
So Kotlin is this new language what Google invented for their mobile phone development and there the layout is defined directly in this language.
00:08:25
Speaker 1
So in the, if you're thinking of Apple, Apple, Apple also using using a similar approach they invented roughly during lockdown.
00:08:34
Speaker 1
So language Swift, yeah, and language Swift.
00:08:37
Speaker 1
And there, if you're defining a layout on your phone or even a layout for your Apple application on your desktop or your laptop, then that's basically you're defining also the layout in the directly in the language Swift.
00:08:51
Speaker 1
So there's also no longer just an XML file out there.
00:08:55
Speaker 1
And so there's some more like convergence, getting rid of these description files on the layout and doing it straight in encoding.
00:09:04
Speaker 1
So, therefore, I would also recommend if you're going online and searching for this kind of stuff, you will find a lot of old and weird implementations.
00:09:18
Speaker 1
using all different kinds of scripting languages to create the layout, but if you want to learn something new or modern, just stick to the code, because there's a convergence somewhere like layout that code is being used, so that's somewhere like started five years ago, and so, and therefore I would strongly recommend that, and then also using commands.
00:09:42
Speaker 1
from these layouts here to influence how this looks like.
00:09:45
Speaker 1
So I'm coming back to this in a minute when I'm showing this into actual running code.
00:09:53
Speaker 1
So the interesting thing is here, so how do we do call, so how does QT callbacks?
00:10:00
Speaker 1
So in QT callbacks,
00:10:05
Speaker 1
are called via so-called signals, which are functions which are connected to a callback.
00:10:12
Speaker 1
And remember when we talked about the callbacks for the ADC converter or for this push button example, you know, we use this writing study with the & sign, Q push button clicked, so that's a prototype here.
00:10:32
Speaker 1
So this just means
00:10:34
Speaker 1
this method here is meant.
00:10:37
Speaker 1
So QPushButtonClick, it's obviously creating a callback when somebody pushes on this reset button here.
00:10:47
Speaker 1
And then we are specifying which instance this push button is meant.
00:10:54
Speaker 1
So that's here the instance of this class QPushButton.
00:10:58
Speaker 1
And then this connects
00:11:00
Speaker 1
to, for example, this window here.
00:11:03
Speaker 1
So if you want to have some action in the window here, like a reset function, and then again, we are connecting this to this instance here.
00:11:10
Speaker 1
Yes, so and therefore, so QT is using this kind of connect function here, by using these how they are called, or function prototypes.
00:11:23
Speaker 1
And then there's also specifying the both instances of this.
00:11:29
Speaker 1
So in this case, instance of the button and the instance here, where this is arriving, very often this is this because it's happening in this window there.
00:11:38
Speaker 1
So you see this using method prototypes or people call it also functors or functors.
00:11:46
Speaker 1
And so they are, just prototypes and then specifying which instances this is.
00:11:53
Speaker 1
So that's a modern way of doing it.
00:11:56
Speaker 1
If you're again going online and searching around, you will also find older constructions from that because QT is so old that this
00:12:07
Speaker 1
Function this method prototype here and did not exist pre 2011, and the and so older older styles used to use the macro here, which was a lot more awkward, but they're just basically abundances and now it's now it's basically also using this C style in a way of connecting it.
00:12:30
Speaker 1
So, okay, so
00:12:36
Speaker 1
there's a typo in there.
00:12:38
Speaker 1
So, how does it, so how does this work here internally?
00:12:42
Speaker 1
So, if you have a QButton class, you clicked in Window class, and we talked about this already the last time.
00:12:51
Speaker 1
So what is actually actually happening internally here?
00:12:56
Speaker 1
Because this connect function here, what does it do actually?
00:12:59
Speaker 1
This connect function internally here uses again a lambda expression to actually do this here.
00:13:07
Speaker 1
So this in the window reset here is then just combined with a lambda function.
00:13:13
Speaker 1
And then internally here, there's also somewhere standard function used.
00:13:20
Speaker 1
in order to connect these two parts here.
00:13:24
Speaker 1
And so, remember, remember when we when I introduced here, the callback function here as a standard function void void, that's that this one that this one one here, so if you have a button class here and there's a there's a there's a function called clicked in here.
00:13:43
Speaker 1
Then, somewhere somewhere inside here, there will be there will be a collection of callback functions here when you're pressing pressing this button here, and then in the window class it will then just call call the reset here via via this lambda function here, so that's the that's the internal working of this.
00:14:03
Speaker 1
QT is doing doing a few of dirty tricks there, you know, so it's not exactly 100%
00:14:09
Speaker 1
C style, it's somewhat like hacking C a bit, and so, but that's just basically roughly what's happening under the hood there, so you can also use lambda functions in the connect function in the connect command, if you like, so you can directly write also lambda function in there instead of this window reset there.
00:14:32
Speaker 1
just in order to link it to the material what you had the last time here, and so and so and so use interface abstract method as a just you know when you are basically using this kind of kind of stuff here, then just then just please
00:14:57
Speaker 1
remember, this is somewhat like a strange QT construct here, but do basically, if you're doing the rest of your coding, like the callbacks for the ADC converter, then that's why I stick to the standard syntax.
00:15:11
Speaker 1
Last year, or the last couple of years, there's always a temptation of some teams that then everything coding everything in the QT style.
00:15:20
Speaker 1
So, as I said, the QT is not 100% C, it's somewhat like a hack.
00:15:27
Speaker 1
And the if you if you're if you're coding coding in QT try to only code the GUI part in that, but not everything else anything else.
00:15:41
Speaker 1
And so the that's just been obviously a bit dry and so let's us let's us go and go back to our ADC converter.
00:15:54
Speaker 1
Example here, that's the one we're doing after this, if you have time, let's just go back here to the let's just let's just show how this actually works.
00:16:06
Speaker 1
So, remember we had here this ADS 11115 demo here, yeah, so and that one where's my window for that, so there's my Raspberry Pi here.
00:16:25
Speaker 1
Let's just go go into this just to just to just to show how this all works.
00:16:32
Speaker 1
So, remember that's our ADS 115, what I was what I've been talking the last last week and last week I rattled a bit through this.
00:16:42
Speaker 1
So, today I'm just going going through the code again and point you out, you know what's your important.
00:16:54
Speaker 1
Oops, for whatever reason I cannot move this.
00:16:56
Speaker 1
So remember, that's here, that's here my Raspberry Pi.
00:17:01
Speaker 1
That's life, that's my finger.
00:17:03
Speaker 1
Not that you think it's just a fake.
00:17:05
Speaker 1
And that's here our ADS115 converter chip.
00:17:11
Speaker 1
What I've done is it's very, it's a bit hard to see.
00:17:14
Speaker 1
So you see here I've added a light sensor on LDR to it here.
00:17:21
Speaker 1
So that we have some analog analog input here to this to this to this converter.
00:17:30
Speaker 1
So if I'm if I if I go back to our example what I what I've what I've shown you the last time.
00:17:38
Speaker 1
So remember the last time here we had this ADS one on 5 printer.
00:17:44
Speaker 1
So if I'm so with a sampling rate of eight of 8 Hertz.
00:17:49
Speaker 1
So, if I'm if I'm moving my it's hard to see here, so if I'm if I'm if I'm moving my hand over it here, so you see it's a numbers numbers are changing, so you can believe me that this is a light sensor here and it looks looks pretty pretty consistent, yeah, that's you know that that's data data changing here.
00:18:18
Speaker 1
Okay, so that's obviously pretty boring.
00:18:20
Speaker 1
So, we what we want is we want to have this obviously as a nice as a nice plot, so not in the way that it's just printing out numbers.
00:18:34
Speaker 1
So, here we had we had this in this example ADS 115 printer.
00:18:42
Speaker 1
Remember that was this example.
00:18:45
Speaker 1
what I've shown you the last time here.
00:18:47
Speaker 1
So we have here this simple printer class here.
00:18:53
Speaker 1
So this method here has ADS 105 sample.
00:18:58
Speaker 1
It's called here as a callback.
00:19:00
Speaker 1
And then the only thing what's inside here is this print, is this print F command here and just printing the value, the value on the screen.
00:19:11
Speaker 1
And so
00:19:12
Speaker 1
And then the main program here is just creating our an instance of this printer here.
00:19:20
Speaker 1
It's creating creating instance of the ADS driver and then and then connecting them both with each other with the with lambda function here and then just starting it.
00:19:34
Speaker 1
And so but so we want to have it have it have it as a nice graphical output and
00:19:42
Speaker 1
And so, if we look into the sub-directory here, you can so it just in case you haven't you haven't got the link here, I just put this in the chat.
00:19:56
Speaker 1
So, if you look here, there's a there's no there's an example here, our T our T plotter.
00:20:03
Speaker 1
I've just updated that because actually the widget I've been using for plotting is no longer supported, so I had to replace it with another one.
00:20:13
Speaker 1
So what we want to have is we want to have something like that, obviously.
00:20:19
Speaker 1
So we want to have a beautiful plot, not just some numbers printed out.
00:20:23
Speaker 1
And so if you go into real-time plotter here, let's see if this works.
00:20:32
Speaker 1
And then we go through the code.
00:20:35
Speaker 1
Real-time plot a tiny window here.
00:20:39
Speaker 1
Let's just make it a bit larger.
00:20:43
Speaker 1
Zoom is slowing this quite down here on my computer, so that's where's my where's my camera there, because you need to believe me that this is happening happening in real time.
00:20:55
Speaker 1
You see it's
00:20:58
Speaker 1
I can change the size of this of this plot window here, and so it's all very interactive.
00:21:06
Speaker 1
And so, if I if I cover cover my hand here, you see you know that this is nicely nicely changing the light intensity here, depending on my light.
00:21:18
Speaker 1
Maybe if I'm if I'm if I if I'm putting my desktop lamp here a bit a bit more over this here, and then the that is going a bit a bit higher.
00:21:31
Speaker 1
OK, so, that works.
00:21:33
Speaker 1
So, now we need to have a look.
00:21:36
Speaker 1
So, how is this, the real-time processing works?
00:21:40
Speaker 1
Also, here there's a reset button just to show you the event-driven stuff from the buttons.
00:21:45
Speaker 1
So, if I'm pressing the reset button, the thing goes to 0, and then the plot plot starts starts again.
00:21:52
Speaker 1
Yeah, so, you see if I'm if I'm pressing that, it's going to zero.
00:21:57
Speaker 1
OK, so simple, simple example.
00:22:01
Speaker 1
So the question is, now, so how does it, how does this work?
00:22:06
Speaker 1
Yeah, so let's just let's just look, oops, no need to do that.
00:22:11
Speaker 1
Let's just look first at the read me.
00:22:13
Speaker 1
Anybody who wants to build that, obviously I obviously need to have the converter chip.
00:22:20
Speaker 1
So the
00:22:22
Speaker 1
These 2 packages are sufficient, so you just need to install Qt 6 based development.
00:22:28
Speaker 1
So this package gives you gives you all the development development libraries you need for Qt Qt version 6.
00:22:37
Speaker 1
So that's all.
00:22:38
Speaker 1
And then and then the this plot here so that we have this beautiful graphical plot here.
00:22:43
Speaker 1
So we don't need to write that.
00:22:45
Speaker 1
because there's already a library also available as package which is called QCustomPlot.
00:22:51
Speaker 1
So QCustomPlot already creates these plots here.
00:22:56
Speaker 1
So there's not much to do to get this running.
00:23:00
Speaker 1
And then you see you just build it in the standard way.
00:23:05
Speaker 1
As I said, I'm expecting from all of the teams at the end
00:23:09
Speaker 1
When I'm testing your code, I only need to write cmake.make and then and then run your program.
00:23:14
Speaker 1
So that's just somewhat like always always the way it should be in terms of the instructions.
00:23:21
Speaker 1
So let's have a have a have a look.
00:23:24
Speaker 1
I just to show you.
00:23:26
Speaker 1
So obviously so I've done that already.
00:23:29
Speaker 1
So nothing really will be happening here.
00:23:32
Speaker 1
And then and then I did a make and then this program is generated here.
00:23:37
Speaker 1
OK, so let's just let's just go now into this into this into this program here, so how this is actually actually being written, so that we get an idea how this works.
00:23:48
Speaker 1
So, here, so the main program you see has an include called called Windows, sorry, window.h window.h is here this header file.
00:24:00
Speaker 1
We're going to have a look into that in a minute.
00:24:05
Speaker 1
So then in QT, the first thing what you always do is you're creating a Q application instance.
00:24:12
Speaker 1
You see without new, just Q application up.
00:24:15
Speaker 1
And this just gets you just the arguments from the main program as a default.
00:24:19
Speaker 1
So then we are creating an instance of this window.
00:24:22
Speaker 1
So window is defined in here.
00:24:24
Speaker 1
Then we are calling window show.
00:24:27
Speaker 1
This then just makes it pop up on the screen.
00:24:30
Speaker 1
And then inside here in the window, I've defined a method called start DIQ.
00:24:34
Speaker 1
This starts the data acquisition.
00:24:36
Speaker 1
And then in the window, I'm starting a timer.
00:24:39
Speaker 1
And this timer is not there to sample the data at this rate.
00:24:44
Speaker 1
This timer is to refresh the window.
00:24:48
Speaker 1
So the window is refreshed 40 times per second.
00:24:52
Speaker 1
This means this here.
00:24:55
Speaker 1
So I'm sorry, every 40 milliseconds.
00:24:57
Speaker 1
Yeah, so Windows is refreshed every 40 milliseconds.
00:25:02
Speaker 1
This means so if you're pressing anything or if you're plotting something, then that's a refresh rate of this thing.
00:25:09
Speaker 1
And then the actual application starts with this up exec here.
00:25:14
Speaker 1
So that's a blocking call.
00:25:16
Speaker 1
So if you are if you are if you're calling up exec then you know the at this at this point here this blocks.
00:25:25
Speaker 1
then it's expected that's it, that the GUI is now taking over.
00:25:30
Speaker 1
So, and then if you are closing the GUI at the end, then basically this returns here and then the program finishes.
00:25:40
Speaker 1
So, the GUI always has the last word, so in the execution and then and then everything runs in the GUI.
00:25:46
Speaker 1
So, if you have asynchronous operations like for measuring the getting callbacks from the ADC converter, so you're starting a thread.
00:25:56
Speaker 1
for the data acquisition, we need to do this before, so that's the reason why the start here queue is happening here.
00:26:03
Speaker 1
Okay, so let's just have a look in the window.h here.
00:26:08
Speaker 1
So, what I've defined here, so you see here the queue custom queue custom plot, so that's a that's this window which is plotting plotting our data.
00:26:22
Speaker 1
Then I'm including here just the box layout here.
00:26:28
Speaker 1
Part of this is the vertical and the horizontal layouts.
00:26:32
Speaker 1
And then I'm including here the push button.
00:26:36
Speaker 1
Yeah, so that's this push button object to reset it.
00:26:39
Speaker 1
Yeah, so yeah, so constructor.
00:26:42
Speaker 1
Then I've got the definition of the message starting data acquisition.
00:26:50
Speaker 1
Destructor here, which is stopping the data acquisition, and then here the most important thing for us is here the has ADS one-on-five sample, so that's a callback from our from our.
00:27:02
Speaker 1
Our driver, from so this function is called is called whenever there's a new just a new sample from the ADC converter has arrived, and then this will be added to the plot and also printed out on the screen.
00:27:18
Speaker 1
So, in here, in the private section here, I'm defining how many data points I would like to plot just for the scrolling.
00:27:26
Speaker 1
And so, here I'm the queue label, queue push buttons, and so, as I said, they're just defined as pointers.
00:27:35
Speaker 1
So, some of you might be might be thinking, O.K., so why is it why has we been ranting last last time about this and saying, so I don't want to have pointers, and suddenly they are pointers.
00:27:47
Speaker 1
So, the exception is if you're using the QT library,
00:27:51
Speaker 1
It wants raw pointers, sadly.
00:27:54
Speaker 1
But the good news is the QT library will tidy it up.
00:27:59
Speaker 1
So if you are closing your program, it will automatically tidy up all these classes which are starting with Q.
00:28:07
Speaker 1
So we don't need to delete them.
00:28:08
Speaker 1
So that's already done by QT itself.
00:28:13
Speaker 1
And then here for this
00:28:16
Speaker 1
For this Q custom plot here, I need to define my animation data, so the data which is scrolling through, and this is here done with a Q shared pointer, so here, and then this is a shared pointer of a QCP data container, which again is a QCP data graph data.
00:28:38
Speaker 1
So I've not invented this, but I've taken this from another example program.
00:28:42
Speaker 1
So, and then I'm defining here the vertical layout and the horizontal layout.
00:28:47
Speaker 1
Remember when I'm here starting this plotter plotter again, so here it's very it's identical to what I've shown you in the example in the lecture.
00:28:59
Speaker 1
lecture slides that, there's a vertical layout here, there's a voltage here of the ADC converter.
00:29:07
Speaker 1
So if I'm changing that, voltage changes here.
00:29:10
Speaker 1
And then there's a reset button, so that's our vertical layout.
00:29:13
Speaker 1
And then we have a horizontal layout where this layout is combined against the plot.
00:29:19
Speaker 1
So what we need is a vertical layout and a horizontal layout, so I'm defining it here.
00:29:28
Speaker 1
so then our reset function, that's the one when I'm pressing the button.
00:29:32
Speaker 1
And then remember there's a timer event, and the timer event is not for creating precise timer timer events.
00:29:38
Speaker 1
The timer event is for refresh.
00:29:40
Speaker 1
So, you know, it's important to notice, to note that QT, QT is not, you know, in our, it's not a not a reliable timing source.
00:29:51
Speaker 1
QT can decide to drop timer events.
00:29:54
Speaker 1
So, it's only there for screen refresh.
00:29:58
Speaker 1
And then here's the last bit, we have our low-level driver, what we talked about the last time, which is creating the data acquisition from the ADC converter and gives us a callback.
00:30:08
Speaker 1
So the callback then ends up here.
00:30:10
Speaker 1
Yeah, so we see ADS sample.
00:30:13
Speaker 1
Okay, now let's look into the window CPP.
00:30:19
Speaker 1
So here we have the constructor.
00:30:23
Speaker 1
Yeah, so that's our constructor.
00:30:25
Speaker 1
So we have the, so here
00:30:28
Speaker 1
So, the first instance what we're creating is now the custom plot.
00:30:31
Speaker 1
So, that's a widget widget for the plotting of the data.
00:30:37
Speaker 1
So, here I'm defining the axis, I'm defining, I'm giving it labels, and then I'm adding a graph, a graph here and creating and then and then this data remember is the object which is containing all the data.
00:30:57
Speaker 1
And there I'm just adding graph data points here to this object.
00:31:05
Speaker 1
And then at the end I'm adding this animation chain of data points to the graph here.
00:31:14
Speaker 1
Again, if you're doing coding yourself, use examples because I would never figure this out from documentation.
00:31:23
Speaker 1
Always use examples where we already queue
00:31:26
Speaker 1
Q custom plot already has done, done a demo or something like this.
00:31:32
Speaker 1
Q custom custom plot has tons tons of demos.
00:31:38
Speaker 1
Q custom plot.
00:31:41
Speaker 1
Oops, is it?
00:31:44
Speaker 1
Yeah.
00:31:45
Speaker 1
So, Q custom plot has a lot of a lot of examples and demos, whatever you want to you want to do.
00:31:51
Speaker 1
You see this program is a monster and can generate you all different kinds of crazy crazy plots even with annotations and something like that.
00:32:03
Speaker 1
And so therefore what I'm doing here is really just a Mickey Mouse version just by adding adding just a simple plot.
00:32:09
Speaker 1
But there's also here basic plotting tutorial.
00:32:12
Speaker 1
So
00:32:13
Speaker 1
So, please look through that if you wanna if you wanna do do your own stuff and look at the example examples what they are what they are providing, but yeah, so I don't want to go too much into detail.
00:32:27
Speaker 1
Then the next thing is we're creating our reset button, then we are then I'm creating his ADC label for the voltage reading, and now the same thing what I've described in the on the slides.
00:32:42
Speaker 1
that we have a vertical vertical layout here, and then I'm adding the voltage reading here to it, then I'm adding the button to it that we have got these two here, you know, on top on top of each other.
00:32:59
Speaker 1
Let me just start the program again that you see that.
00:33:08
Speaker 1
Yeah, so where is it?
00:33:11
Speaker 1
Yeah, so here we have now the now the vertical layout, so we've got here the voltage the voltage reading up here and then the reset button down down here, so now the final step is here horizontal layout, so we want to have these two and then the then this plot here with our data next to it, so we're using a horizontal layout.
00:33:37
Speaker 1
And then, and then we're popping this all at the end here into the set layout function, which is part of QT.
00:33:46
Speaker 1
So, that's us that's us all done in the constructor.
00:33:49
Speaker 1
So, then in the main, so once this has happened here, remember in the main program here, the next thing is start DAQ.
00:34:00
Speaker 1
So, that's starting our data acquisition.
00:34:04
Speaker 1
So, let's have a look.
00:34:06
Speaker 1
What's happening happening there that the start the queue?
00:34:13
Speaker 1
Yeah, so in the start in the start the queue here, what I'm doing is here, so remember the ADS 115 is our instance of our low-level data acquisition driver, what we talked about the last time.
00:34:26
Speaker 1
So I'm registering now a callback.
00:34:29
Speaker 1
So here, Lambda function, and Lambda function registers the has
00:34:35
Speaker 1
ADS 115 sample here, yeah, so that's just what I'm registering here, and I'm pointing in this case is pointing to this to this to this instance here, so this one here registers this function down here, yeah, so and then with that, there is a driver class now I need to call this function has ADS 115 sample down there, then I'm creating an instance here of the settings.
00:35:05
Speaker 1
That's also something I expect you to do.
00:35:09
Speaker 1
If you have settings for your driver or settings for something like this, create a class, sorry, a class or a structure, create a structure where all your settings are inside, with default settings, and then modify whatever you need in there.
00:35:28
Speaker 1
So in this case, you see I'm setting as sampling rate, and then I'm setting this here to this constant,
00:35:35
Speaker 1
FS sixty-four Hertz.
00:35:37
Speaker 1
Yeah, so this means I'm setting this to sixty-four Hertz sampling rate, so then ADS 115 is our start function of the class, and I'm giving it here this configuration and setting this then with all the default settings also to this sampling rate of sixty-four Hertz.
00:35:57
Speaker 1
Then, as a final thing here, I'm starting the timer.
00:36:02
Speaker 1
That's actually actually twice.
00:36:03
Speaker 1
I that's actually a bug here in my program because I'm starting the timer also here, isn't it?
00:36:08
Speaker 1
Yeah, so therefore I should fix that.
00:36:12
Speaker 1
So, if I main, so there's a start timer, start timer twice, that's actually actually a bad thing.
00:36:21
Speaker 1
So, the where's my where's my plotter?
00:36:28
Speaker 1
Let's see.
00:36:28
Speaker 1
So, if we...
00:36:31
Speaker 1
If you go into main here, so we probably don't need that.
00:36:39
Speaker 1
Let's see.
00:36:47
Speaker 1
And we can recompile it and see if it still works regarding this.
00:36:55
Speaker 1
As you see, it's running on the, it's compiling on my Raspberry Pi here.
00:37:02
Speaker 1
It's A Raspberry Pi 4.
00:37:05
Speaker 1
Raspberry Pi 4 is not the fastest one, but you see it's still it's still OK to do development directly on it.
00:37:15
Speaker 1
OK, so it's still refreshing and still working, so that was one one timer too much.
00:37:25
Speaker 1
OK, so while we are while we are here, so now I fixed this.
00:37:29
Speaker 1
So, what is the git command now to commit that?
00:37:33
Speaker 1
So, before you all fall asleep there at the other end, so, how do I how do I do it?
00:37:41
Speaker 1
Do I commit commit that now?
00:37:43
Speaker 1
So, now that I fix this bug here, so what do you what do I need to write in the command line here now to now to make it just to just to read just to fix it also on my on my GitHub here?
00:38:01
Speaker 1
So, any git commit, yeah, exactly, yeah.
00:38:05
Speaker 1
So, git, I cannot cannot type so late, minus MMCC.
00:38:13
Speaker 1
I always also minus AA means means everything, so anything what has been has been changed is recorded M, yeah.
00:38:27
Speaker 1
Removed, it's very slow here with Zoom running here, removed second timer start command or something like that.
00:38:44
Speaker 1
Okay, so now it's now it's committed and then I then I then I push it and
00:38:56
Speaker 1
So, hopefully, hopefully, my commit message is, I see here, RT plotter removed second timer start command.
00:39:12
Speaker 1
I've removed it here, so let's see, let's have a look in the history here, yeah, and there it is, you know, this thing is now gone and it's still working.
00:39:26
Speaker 1
OK, great.
00:39:26
Speaker 1
So, we have also fix fix a small bug here, so I'm expecting from all of you that you, working working away with your with your git with your git commands, you probably only need need roughly five of them or something like this, make you make yourself a nice cheat sheet for that.
00:39:48
Speaker 1
Let's just go back here to the RT plotter, going going through the code, so we
00:39:55
Speaker 1
So, we started the data acquisition process here, and so now, remember the so the only bit what is now remaining here, remember we've got this callback here, so it has A.D.S.
00:40:07
Speaker 1
115 sample, and so the callback needs to now shift shift the data of the data through, and so this is done done here by this year, yeah, so we so we
00:40:22
Speaker 1
Starting, starting here from the animation data at the end and working ourselves to the beginning here and shifting the values, the values in order to the previous value to the next value here, and then just adding adding our new sample here at the start, and then also the other thing is here.
00:40:43
Speaker 1
Remember, I'm also updating the text reading in the window there.
00:40:49
Speaker 1
Where is it here?
00:40:50
Speaker 1
Let me just...
00:40:51
Speaker 1
Start this again.
00:40:57
Speaker 1
Yeah, so remember it's not just the plotting which is updated here.
00:41:06
Speaker 1
Yeah, so it's so it's not just the scrolling here of the plots here, what is happening here, but we have also here I'm changing the text value here, the voltage value.
00:41:20
Speaker 1
So, voltage value is here also updated here, so I'm creating temporary character array, and then I'm printing here this value in it, and then I'm then I'm using the remember ADC label is here, this the voltage label here, and then I'm using the message set text.
00:41:37
Speaker 1
So, the interesting thing is anything of this is not updated at this moment, yeah?
00:41:43
Speaker 1
So, the data is updated, but it's actually not plotted at this moment.
00:41:49
Speaker 1
So the plotting is only happening happening here when this timer event is happening here.
00:41:53
Speaker 1
So remember what we just also fixed.
00:41:56
Speaker 1
So at the moment when the QT timer fires, then the window is updated.
00:42:03
Speaker 1
So that's the that's the idea that's the idea behind that.
00:42:07
Speaker 1
So and therefore this is completely decoupled and the reason behind this is
00:42:13
Speaker 1
That you might have might have not noticed this here, but this plotting here is happening just now via via remote SSH.
00:42:25
Speaker 1
So, here this is running on my on my Raspberry Pi here, yeah.
00:42:30
Speaker 1
So, and so what I'm what I'm doing here is in this in this window I am
00:42:37
Speaker 1
So here this is my desktop computer I'm just now doing my lecture on.
00:42:41
Speaker 1
And what I did before is I did an SSH into my Raspberry Pi.
00:42:47
Speaker 1
And then, and I use this option here, minus X.
00:42:54
Speaker 1
So the minus X option redirects the graphical output to my screen here.
00:43:00
Speaker 1
And that's obviously depending on my network and on the Raspberry Pi.
00:43:05
Speaker 1
not necessarily the fastest fastest connection.
00:43:09
Speaker 1
It's a Raspberry Pi 4.
00:43:11
Speaker 1
I think the Ethernet connection is also only 100 megabit and not a gigabit.
00:43:16
Speaker 1
And so with that, the transmission might be a bit erratic.
00:43:23
Speaker 1
And QT is taking care of this.
00:43:25
Speaker 1
So therefore, if I'm starting this program here and
00:43:30
Speaker 1
And the refresh cannot be done at this, cannot be done every 40 milliseconds.
00:43:37
Speaker 1
QT will just drop frames.
00:43:41
Speaker 1
So, QT reserves the right to change the timing of this output here in the way that it's adjusting to the speed of the connection here.
00:43:55
Speaker 1
So, you see here the Ethernet connector here, and it's a Raspberry Pi 4, and I'm pretty sure it's only 100 megabit and not a gigabit.
00:44:04
Speaker 1
So, and therefore the speed is not the greatest, but it's a very, very flexible way.
00:44:10
Speaker 1
So,
00:44:11
Speaker 1
As you know, I'm doing robotics, and so if you want to run directly plotting program on a robot via Wi-Fi connection, it doesn't matter because QT will just adjust the speed of the plotting regarding this.
00:44:24
Speaker 1
And so, therefore, that's a fantastic, you know, way of dealing with that.
00:44:31
Speaker 1
Also, that's also the reason why I've why it's useful to have
00:44:36
Speaker 1
Ubuntu running on your laptop in the lab, that you're able also to do this SSH minus minus X here, that you also can do a graphical redirection to your laptop also for debugging purposes.
00:44:49
Speaker 1
Is this pretty useful?
00:44:55
Speaker 1
Okay, so that's basically what I've
00:45:05
Speaker 1
been talking about here, so for animation such as plots or games, use the update function, so the update function triggers a screen update.
00:45:17
Speaker 1
Sometimes you also need to ask the widgets to update, and so please never use QT timers to create
00:45:28
Speaker 1
actual timer timing events, for example, reading from a sensor or something like this, because there's no guarantee that QT will be really reliable there.
00:45:40
Speaker 1
I mean, there are QT also has somewhat like more high precision timers, but again, you know, I would not would not trust that, and there's also not a way of dealing with here, so we so we're doing the timing with low-level functions and with GPIO pins from external events.
00:45:57
Speaker 1
so, finally, if you want to make your own widget, so it's not so that obviously you have to only use the widgets which are there, then you can also create create your own, so and it's very easy.
00:46:14
Speaker 1
So, the if you are if you are if you're creating a so inheriting queue widget, and if you're doing this, there's a there's a method in there which is called paint event.
00:46:27
Speaker 1
And in this paint event, as the name says, the widget needs to paint itself.
00:46:33
Speaker 1
So, therefore, inside here in the paint event, you have...
00:46:39
Speaker 1
basic, functions there, like drawing a line, for example, or so, and then you can, create your own plots or create, animations or whatever you like or something like this.
00:46:54
Speaker 1
so, therefore, again, paint event is not directly called, but paint event is again called after update has been triggered from the main program.
00:47:06
Speaker 1
So, we have no control how often paint event is called.
00:47:10
Speaker 1
That's just up to QT, depending basically on the speed of your computer or speed of the connection when you're doing remote display or something like that.
00:47:22
Speaker 1
And so, and therefore, so anything in here you cannot trust that it's happening at a certain frequency or so, but it's obviously will be happening eventually there.
00:47:32
Speaker 1
And so,
00:47:36
Speaker 1
Again, again with QT, just before I finish up with this here, QT is super complex and if you're writing your own stuff, always use examples.
00:47:51
Speaker 1
So the way I'm coding in QT is that I'm looking for QT examples which are very close to the stuff what I want to do, and then I hack it and modify it.
00:48:02
Speaker 1
So
00:48:04
Speaker 1
The QT has on the website, and also obviously QT has been used for 20 years.
00:48:09
Speaker 1
There are lots of examples out there, and use the example which is close, which is as close as possible to what you want to do, and then and then just modify that in terms of the data plotting, because you're probably also going quite a few going going to do data plotting.
00:48:32
Speaker 1
Where's this?
00:48:32
Speaker 1
Where's the other screen here?
00:48:35
Speaker 1
So there's a, let's just go on my desktop here, which is a bit, a bit, a bit, a bit faster.
00:48:43
Speaker 1
So sandbox.
00:48:45
Speaker 1
So the QQ custom custom plot demo.
00:48:50
Speaker 1
So in my, in my GitHub, there's also another example there.
00:48:59
Speaker 1
If we,
00:49:01
Speaker 1
If you go and go back to my GitHub here, where is it there?
00:49:08
Speaker 1
So that you have also talking about examples.
00:49:12
Speaker 1
So you have obviously the example, the example now in here in a real-time plotter, which is hopefully helping you to get started.
00:49:21
Speaker 1
The other thing is here, what I also updated today is here, there's another example called QCustomPlotDemo.
00:49:28
Speaker 1
And this is a bit more involved that you see basically if you want to do more scientific plotting or something like this.
00:49:36
Speaker 1
So let me just see if this works, if this works here.
00:49:44
Speaker 1
QQ custom plot demo.
00:49:47
Speaker 1
Yeah, so you see here that's the way that's the way it looks like.
00:49:55
Speaker 1
So you see there's a real-time animation in there that's actually I use that one actually to hack it backwards to my ADC example code.
00:50:04
Speaker 1
So there's a real-time animation here and you see it's running quite choppy here just now.
00:50:09
Speaker 1
So therefore the QT timer events are, QT is dropping quite a lot of plot events here because Zoom is draining my computing power here.
00:50:19
Speaker 1
So, you see also two other plots here, but you see there are also some interactive functions in here, yes, select select to drag and drop individually.
00:50:28
Speaker 1
Let's see, yeah, so, if I if I use my mouse here, so I so I can move the coordinate system, which is which is quite cool here, double click to change the change the labels here, yeah, so I so I can.
00:50:48
Speaker 1
Also, do we do this here, for example?
00:50:50
Speaker 1
so, you see it's a lot more interactive than the one what I have shown you shown you in this plotting plotting of my ADC data here, and so I can also add random random random graphs here and remove all graphs and add random graphs again.
00:51:13
Speaker 1
So, you see...
00:51:15
Speaker 1
this is somewhat like a all singing, dancing, dancing example here.
00:51:21
Speaker 1
What is this a question to everybody here?
00:51:25
Speaker 1
Where the data came from currently or it randomly generated?
00:51:30
Speaker 1
Well, in this example, in this example here, the data was randomly generated.
00:51:35
Speaker 1
You know, look, at the code.
00:51:37
Speaker 1
it's just it's just basically like a generated by random number generators, so that you can try it out without without having a data acquisition card card about, and you see you can create beautiful art with that.
00:51:52
Speaker 1
So, this example is just it's it's a lot more involved, but it's just basically the full, you know, just a fully fully singing dancing dancing example.
00:52:04
Speaker 1
It's also using style sheets.
00:52:06
Speaker 1
It's using all different kinds of layout elements here like frames and changing size policies, how stuff is stretched and modified and something like this.
00:52:18
Speaker 1
And so therefore, have a look there.
00:52:20
Speaker 1
You see there are also loads of connect commands in here.
00:52:25
Speaker 1
Sadly, I should have modified this using still the old style here with macros to connect connectors here.
00:52:33
Speaker 1
That's no longer needed.
00:52:34
Speaker 1
What I told you, can use function prototypes for that.
00:52:37
Speaker 1
Maybe I'll just fix that later on.
00:52:40
Speaker 1
But yeah, but you see it's a singing-dancing example, pretty long and involved.
00:52:45
Speaker 1
And you see here there's a random random number number generation here with these sine waves in this part here.
00:52:53
Speaker 1
Yeah, so but QQ custom plot is an absolutely amazing amazing program.
00:52:57
Speaker 1
You can do all different kinds of fancy stuff with that.
00:53:01
Speaker 1
So I really love that.
00:53:02
Speaker 1
And it's also well maintained.
00:53:03
Speaker 1
And as I said, it's a package under Ubuntu.
00:53:06
Speaker 1
So we just do up to install and job done.
00:53:10
Speaker 1
So this one you can try out without any additional hardware like my ADC converter.
00:53:16
Speaker 1
So just fork this here, sorry, or just clone it and have a play tonight with this example here.
00:53:26
Speaker 1
It also compiles.
00:53:27
Speaker 1
Without any problems under under Ubuntu, so yeah, so I just shown it shown you it runs under under Ubuntu as well, and so it's on there for yeah, so we just need to need to do these two commands here and job done, basically.
00:53:42
Speaker 1
Okay, so that's us that's us all for today, and then I'm going to see you see you next Wednesday at the next lab.