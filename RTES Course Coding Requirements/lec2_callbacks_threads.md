0:14:12
Speaker 1
There we go.
00:14:13
Speaker 1
So, here we have, I have a method called start, and in the method start here, I'm starting I'm starting a thread, and then and then the worker and the worker is down down here, so the worker here.
00:14:34
Speaker 1
It's now running in a thread.
00:14:37
Speaker 1
There's a get character command, and then and then here I'm calling a function, yeah?
00:14:42
Speaker 1
So, that's the idea, that's the idea behind this, and so, if I'm if I'm starting starting this keeper keypress demo program, where is it here?
00:14:55
Speaker 1
Demo standard function, you know, that's just basically here's this program what I've just shown to you here, yeah?
00:15:03
Speaker 1
So,
00:15:05
Speaker 1
So, general idea is, so we have a blocking operation get character, so this is this loop here is running in a thread, and then and then when this unblocks then a function is called and then the thing goes back to sleep, so that's the idea behind behind that, and so we so that's a general idea, so you're creating a thread with standard thread here.
00:15:32
Speaker 1
And then I'm running a loop where you have blocking IO here, and then you're calling a function.
00:15:38
Speaker 1
So that's the general concept behind that.
00:15:42
Speaker 1
So have a play with that here.
00:15:44
Speaker 1
As I said, it's on GitHub.
00:15:46
Speaker 1
I just created this yesterday, actually, just as a simple example, because I thought the previous one from last year was a bit too complicated.
00:15:55
Speaker 1
But that's just more focusing really on the basics and seeing how this works.
00:16:03
Speaker 1
So the question, the question is now, so how do we actually transmit this event here to the other class called saying boo?
00:16:17
Speaker 1
So we have here the event.
00:16:20
Speaker 1
So if I go back here, so we've got this function has event.
00:16:26
Speaker 1
But
00:16:28
Speaker 1
The actual boo here is happening in this class here.
00:16:32
Speaker 1
So it's not happening here, but we would like to transmit this here from our, let's say, driver class or the class which is receiving the hardware event and transmitting that to a class which is doing something like with that.
00:16:51
Speaker 1
So we call this basically a publisher and subscriber framework.
00:16:56
Speaker 1
So we have a publisher where the event is created, and then we have a subscriber which is doing something with it.
00:17:04
Speaker 1
So and this is done, which is called a callback.
00:17:09
Speaker 1
So you see it up here.
00:17:11
Speaker 1
You know, that's a callback.
00:17:13
Speaker 1
which is transmitting then this has event here into this class here encoding a method which is then actually printing that.
00:17:24
Speaker 1
So the question is now, so how do we do that?
00:17:27
Speaker 1
So in standard C, so if you were just writing a microcontroller, you would create a function pointer.
00:17:34
Speaker 1
So in C
00:17:38
Speaker 1
A function coin pointer does not work this way because we have actually two things to do.
00:17:44
Speaker 1
So we have an instance of this class here and then within the class there's a certain method in there which is called.
00:17:51
Speaker 1
So somewhat like 2 pointers we need to transmit.
00:17:54
Speaker 1
So not just one.
00:17:55
Speaker 1
So therefore it does not work directly with a function pointer.
00:17:59
Speaker 1
And so we need to think of something else where we are able to transmit the has event
00:18:06
Speaker 1
here to this event printer, printer boo.
00:18:11
Speaker 1
So there are two ways just now, which are popular in the C community, how to do it.
00:18:21
Speaker 1
So in terms of callbacks, so I'm talking about both of them.
00:18:25
Speaker 1
But in the next lecture or lectures afterwards, I'm probably more talking about standard function.
00:18:32
Speaker 1
So there are two approaches.
00:18:34
Speaker 1
The first one is using
00:18:36
Speaker 1
Standard template library, so-called standard function.
00:18:40
Speaker 1
So, standard function is a nice wrapper which is able to that you're able to call methods within a class.
00:18:48
Speaker 1
And then the other approach is so-called interface classes.
00:18:50
Speaker 1
So, interface classes don't need any kind of special library like the STL.
00:18:56
Speaker 1
They work essentially with anything.
00:19:00
Speaker 1
And so, the interface classes, they are heavily inspired by Java coding.
00:19:06
Speaker 1
So, with those who are doing Java coding, knowing that they are used everywhere, in the Java framework to do callbacks and are quite popular, they are in C there were also the, there was a way of choice until basically the STL library became stable, and now I recommend use, standard function for the callbacks here.
00:19:31
Speaker 1
So anything else, what you're finding somewhere out there is probably outdated.
00:19:36
Speaker 1
So please don't use bind, for example.
00:19:39
Speaker 1
So that's just no longer used, because it has very strange ways of specifying the arguments.
00:19:47
Speaker 1
And so avoid this.
00:19:49
Speaker 1
So use either standard function or the interface classes.
00:19:53
Speaker 1
So I'm talking about both of them.
00:19:57
Speaker 1
So
00:19:59
Speaker 1
So let's just stick first call backs with standard function.
00:20:03
Speaker 1
So standard function means here it's a library says standard template library.
00:20:09
Speaker 1
It's library with templates.
00:20:11
Speaker 1
So the template here is in this is in this bracket here.
00:20:14
Speaker 1
So I'm defining here a function prototype which returns void and receives void because in this case I don't need need need anything transmitting except of the event itself.
00:20:30
Speaker 1
just a key press, so I don't need to say what the key was, because it's always enter, and so I'm creating a function function template with this here, using callback function equals standard function void void, and then and then I'm then I'm creating this instance variable here, callback function has event, and this acts
00:20:56
Speaker 1
As a placeholder, so for a method in a class, so a placeholder means it's not yet defined, so it's a bit like at this point, you like a null pointer, but it's a lot more richer because it's managed by the standard template library, and
00:21:17
Speaker 1
And so, this thing sits here in the publisher class.
00:21:21
Speaker 1
So, here we have now has event and we can leave this unspecified at this point, so that anything what is further downstream here can be can be basically connecting connecting to that.
00:21:38
Speaker 1
So, that's the that's the idea that's the idea behind that.
00:21:42
Speaker 1
So,
00:21:44
Speaker 1
So, we leave this here unspecified, so the has event here at this point is just empty, yeah, so there nothing would be happening, and if you already had a look close look here at my code, what I had here before, I think there was there was some.
00:22:02
Speaker 1
No, I thought I don't know, it was just in the C program, so it has so it has the event is just basically empty.
00:22:13
Speaker 1
So, if I'm if I'm if I'm going here into my program, where's my where's my Emacs gone?
00:22:21
Speaker 1
I don't know, I've closed it here, Emacs standard function.
00:22:30
Speaker 1
Event callback, so that's key press publisher standard function age, there we go.
00:22:42
Speaker 1
So, if I go down here to the so here's the here's a callback defined, yeah, so or the prototype.
00:22:57
Speaker 1
So that's my callback function, standard function, void, void.
00:23:04
Speaker 1
And then I'm creating down here in the private section the actual function variable of this.
00:23:11
Speaker 1
So as I said at this point, it will be just empty.
00:23:15
Speaker 1
And in order to make sure that I call this only when it's defined, so I just actually do an if callback function.
00:23:23
Speaker 1
So if it's not just a null pointer, and then I'm calling this function here.
00:23:27
Speaker 1
So as I said just now, it's undefined, and we are going to define this later on in the next step.
00:23:36
Speaker 1
So that's the idea behind that.
00:23:39
Speaker 1
Let's go over here.
00:23:42
Speaker 1
So
00:23:46
Speaker 1
So, the interesting thing is now, so how do we how do we connect that?
00:23:51
Speaker 1
So, the callback function here, this does this does now is connected to this receiver class here.
00:24:04
Speaker 1
So, the subscriber
00:24:08
Speaker 1
We have got this subscriber class here saying Boo.
00:24:11
Speaker 1
Yes, remember we want to print Boo on the screen, and so and the way we are doing this here is that this Boo class here or the structure in this case, because I was lazy because I didn't want to have it public-private.
00:24:26
Speaker 1
So then I registering this here with this register event callback here, and then and then and then this is called here.
00:24:37
Speaker 1
at the moment when this event has happened here, where was my loop here, yeah, so this has event here that this is then just then just called when I'm when I'm pressing the return button here, yeah, so if I'm if I if I'm going back to my program here, there we go, yeah, so here we have the key press subscriber.
00:25:07
Speaker 1
And now we have a function in here which is called key event, or a method, sorry, a method key event, which is saying boo.
00:25:19
Speaker 1
And then this is printed here.
00:25:22
Speaker 1
So we need to simply connect now this function key event to this standard function here.
00:25:34
Speaker 1
And for this purpose, I've got this function register event callback here, which is then just registering this function boo in here.
00:25:44
Speaker 1
So we see here this unspecified prototype of the callback function here is then just filled here with this struct subscriber key event.
00:26:01
Speaker 1
And then this is printing out.
00:26:03
Speaker 1
this simple message here, so was it here?
00:26:13
Speaker 1
Demo blocking IO hang on, that was a wrong one.
00:26:19
Speaker 1
Demo standard function there.
00:26:21
Speaker 1
So, every time when I'm I hope you hear that when I'm pressing the enter button that is now printing out this boo thing here.
00:26:36
Speaker 1
So, the only remaining question is, and is basically how does the main program actually registers the, this key event to the callback function and the registration is happening happening here in this slightly cryptic cryptic syntax here.
00:27:02
Speaker 1
So you see here register event callback.
00:27:05
Speaker 1
So I'm creating here an instance of the publisher.
00:27:10
Speaker 1
And then I'm creating the instance of the subscriber.
00:27:14
Speaker 1
And then I'm here connecting the publisher function to the subscriber function.
00:27:21
Speaker 1
So and this is done here with this line of code here.
00:27:28
Speaker 1
So anybody out there who is still awake and listening in, so what is this weird construction?
00:27:35
Speaker 1
What does it look like or what is it?
00:27:38
Speaker 1
So here's the register event callback, and then I'm saying here, I would like to register the key press subscriber and the key event, so that the thing is saying boo.
00:27:49
Speaker 1
So what is this strange thing here?
00:27:51
Speaker 1
And sign, brackets, blah, blah.
00:27:54
Speaker 1
So what?
00:27:55
Speaker 1
What is this for a strange construction?
00:27:59
Speaker 1
So anybody putting this into the chat?
00:28:03
Speaker 1
Has anybody seen that?
00:28:05
Speaker 1
Of course, standard function does not like function pointers, but it likes that.
00:28:14
Speaker 1
So what is that?
00:28:17
Speaker 1
You know, this strange construction here.
00:28:21
Speaker 1
I hope you can see that in order out there.
00:28:24
Speaker 1
Reference.
00:28:25
Speaker 1
Yeah, there's a reference.
00:28:27
Speaker 1
Yeah, that's right.
00:28:28
Speaker 1
Yeah, so Becky is right.
00:28:31
Speaker 1
There's a reference here.
00:28:32
Speaker 1
So the and sign says it's a reference.
00:28:35
Speaker 1
So what does it mean when there's a square bracket and there's just an add sign in there?
00:28:44
Speaker 1
And then there's a round bracket afterwards.
00:28:46
Speaker 1
Typical C construction, only special characters, and looks absolutely terrible, you know, so and
00:28:53
Speaker 1
What is the idea behind that?
00:29:04
Speaker 1
Anybody out there, except of Becky being...
00:29:07
Speaker 1
being still awake and listening in.
00:29:14
Speaker 1
Yeah, exactly.
00:29:15
Speaker 1
It's a lambda function.
00:29:19
Speaker 1
So that's a lambda function.
00:29:21
Speaker 1
So this means the end sign means it captures all the variables which are here.
00:29:28
Speaker 1
So in this case here, the key press
00:29:30
Speaker 1
And the key press publisher and key press subscriber, so the end sign means it's capturing these two variables.
00:29:38
Speaker 1
And they're available in the lambda function.
00:29:41
Speaker 1
So I can access these two guys here as a reference.
00:29:46
Speaker 1
So that's the reason why this thing is here.
00:29:49
Speaker 1
So with that, I'm able to access a key press subscriber and the method key event.
00:29:55
Speaker 1
That's the idea behind that.
00:29:57
Speaker 1
So, therefore, if you are registering something in this publisher subscriber framework, you have to use a lambda function for that.
00:30:06
Speaker 1
So, when the lambda function creates a connection between these two publishers and subscribers, and the end sign means it's a reference, so therefore there's nothing wasted in terms of, you know, copying stuff over or something like this.
00:30:24
Speaker 1
So, it's very fast.
00:30:27
Speaker 1
and then you see we are starting with the publisher with the start function as a thread, and then afterwards, the whole thing is running.
00:30:37
Speaker 1
And then in the main program here, there's nothing happening here because everything is done in the thread.
00:30:42
Speaker 1
So the thing is just sleeping.
00:30:45
Speaker 1
Okay, so in order to connect that, remember, we need to use a lambda function for this.
00:30:52
Speaker 1
So, now let's us go to the second option, and I should have drawn A2 in here.
00:31:00
Speaker 1
So, the so callbacks in our using using C interface classes.
00:31:07
Speaker 1
So, we don't use lambda functions, but we're using so-called interface classes, interface classes to do the transmission from one class to the next one.
00:31:19
Speaker 1
So, we have here again
00:31:21
Speaker 1
our C class here, and we would like to call something here.
00:31:26
Speaker 1
And the idea is now that we are creating a third class, and the third class acts basically as a glue between our publisher and the subscriber class.
00:31:40
Speaker 1
So we're creating something like a glue between that, and then we're defining a callback inside there.
00:31:48
Speaker 1
So that's the idea behind this.
00:31:49
Speaker 1
So we're creating something like a
00:31:51
Speaker 1
And so this glue is defined as an abstract prototype, and then the receiver class has to fill it.
00:32:02
Speaker 1
So that's the way it's working.
00:32:04
Speaker 1
So if we are creating this class here, callback interface, so you see that there's this one single method inside here, has event.
00:32:16
Speaker 1
And this interface
00:32:17
Speaker 1
is defined virtual equals equals 0.
00:32:21
Speaker 1
So what does it mean if I'm writing virtual blah blah blah equals 0?
00:32:28
Speaker 1
Anybody out there in the chat, what does it mean?
00:32:34
Speaker 1
So if you are, if you are, if I'm writing a function in this style here, has event equals 0, because that's important here.
00:32:47
Speaker 1
Yeah, exactly.
00:32:48
Speaker 1
It's a pure virtual function.
00:32:50
Speaker 1
So the function actually no longer, not yet exists.
00:32:53
Speaker 1
Yeah, so it's similar thing, remember, with standard function what we had before.
00:32:58
Speaker 1
Yeah, in the other framework here, remember the callback function has event, which was undefined here at this point.
00:33:07
Speaker 1
Yeah, so, and it will be only filled with live later on if you want to, for example, print boo on the screen.
00:33:14
Speaker 1
Yeah, so
00:33:15
Speaker 1
So the idea here is we are creating this virtual function here, which is purely virtual function.
00:33:21
Speaker 1
There's nothing behind there except of its name.
00:33:24
Speaker 1
It cannot be compiled because there's nothing behind it.
00:33:28
Speaker 1
But what we can do is here in the publisher class, we can define a callback interface.
00:33:35
Speaker 1
And using this here, even if it's here still undefined,
00:33:40
Speaker 1
We can still define a pointer on that, so that's the idea behind that.
00:33:44
Speaker 1
So, we can define a pointer on this, and then anything what is inherited from there can still be used.
00:33:53
Speaker 1
So, we, and then in the worker, we are doing something quite similar to the standard function.
00:34:00
Speaker 1
So, here again, we are saying if the callback interface is there, so this pointer here.
00:34:07
Speaker 1
then we are calling the method has event, so if this exists.
00:34:12
Speaker 1
So you see it's pretty similar to standard function, but here we are just basically not using the standard template library, which is probably doing something internally quite similar to this, but we are doing it basically by ourselves.
00:34:28
Speaker 1
So we have here creating this virtual function here, and then we
00:34:34
Speaker 1
can fill it with live later on if you know what has event should do.
00:34:38
Speaker 1
For example, printing again boo on the screen.
00:34:43
Speaker 1
And so we have an abstract prototype here.
00:34:46
Speaker 1
So that's our glue, remember, between the publisher and the subscriber.
00:34:53
Speaker 1
And then here, then later on, if we want to use it to print the word boo on the screen, then we just inheriting
00:35:02
Speaker 1
this callback interface here into a new struct, and then just filling this here with live.
00:35:08
Speaker 1
Yeah, so we're adding here void has event override boo.
00:35:12
Speaker 1
Yeah, so we just to be sure that we are that we don't misspell it, usually we are writing override that this function here, the this purely virtual function here is overwritten by this actual actual method here, and then and then we can use that.
00:35:30
Speaker 1
and register this in the publisher class to print to print out this message here.
00:35:38
Speaker 1
So, these are the two ways of dealing with that.
00:35:44
Speaker 1
So, we have we have on the one hand either use standard function or you use callbacks with C interface classes.
00:35:53
Speaker 1
So, these are the two ways of dealing of dealing with that.
00:35:58
Speaker 1
So,
00:36:00
Speaker 1
You can choose whatever you like.
00:36:02
Speaker 1
I would say standard function is now becoming more and more popular.
00:36:07
Speaker 1
just a C dialect there is now pretty stable, the STL.
00:36:13
Speaker 1
And so therefore I would recommend that callbacks if you like one, if you want to do that, feel free as well.
00:36:22
Speaker 1
Let's just quickly talk about callback callback arguments.
00:36:27
Speaker 1
so, if you have a callback interface or standard function and you have just one single value, for example, like voltage from an ADC converter or something like that, it's obviously a no-brainer to do a just a just a value transmission here, you have float vault and then everything is fine.
00:36:52
Speaker 1
so, what do we do now?
00:36:54
Speaker 1
What do we do in modern C in modern C if you have more than one value?
00:37:00
Speaker 1
And a lot of people don't know really about the flexibility of the struct construct, yeah?
00:37:10
Speaker 1
So, if you are if you have something which is containing 3 values, for example, from an accelerometer and IMU.
00:37:19
Speaker 1
then create a struct, so-called called sample, and put your put your 3-3 fluids inside here, and then and then just transmit that here, rather rather as a reference, you know, in your in your event framework here, so the so the struct sample here, there's a lot of magic behind there, so if you also
00:37:44
Speaker 1
assigning it to something else and something like that.
00:37:47
Speaker 1
So the C compiler would then just always make deep copies of all the internal variables.
00:37:55
Speaker 1
So it's a very flexible construct.
00:37:58
Speaker 1
So I would recommend if you're looking into structs and also about look into copy constructors and the rule of three or rule of five.
00:38:10
Speaker 1
to look basically at the flexibility of that.
00:38:12
Speaker 1
So it's very popular nowadays also to put configuration information into these things.
00:38:19
Speaker 1
So obviously what you also can do is if you want to use a standard template library, you can also use, for example, an array.
00:38:28
Speaker 1
Standard array in a callback is also very fast because it has a fixed number of elements.
00:38:36
Speaker 1
And again, you can transmit this as a reference if you like.
00:38:41
Speaker 1
So make sure that you use the standard template library wherever it's possible, because you are avoiding pointers with that.
00:38:54
Speaker 1
Obviously, if you now know the size of an array, you can also, for example, transmit an array with constant length.
00:39:03
Speaker 1
This is also very, very safe because, again, you can transmit this as a reference and avoiding pointers.
00:39:11
Speaker 1
So, in general, generally avoid raw pointers at all costs, because that is obviously very dangerous in coding and in modern.
00:39:21
Speaker 1
C coding, you hardly find any raw pointers anywhere.
00:39:26
Speaker 1
So, and therefore, try to minimize that, especially if you have to create this new and delete.
00:39:36
Speaker 1
So, as a final bit here, let's just look into event-driven GPIO.
00:39:44
Speaker 1
So, why is event-driven event-driven GPIO so
00:39:51
Speaker 1
so important.
00:39:51
Speaker 1
Let me just quickly get the terminally out of the way.
00:39:57
Speaker 1
So event-driven IO is pretty important for most of the sensors, because imagine you have an ADC converter here, and you set the ADC converter to a sampling rate of 10 hertz or 250 hertz, and the ADC converter is working, you know, by itself.
00:40:21
Speaker 1
But so we just don't know when the ADC converter has new data.
00:40:26
Speaker 1
So, in the obviously in the worst case, you're just doing polling and checking this converter all the time and draining the battery as quickly as possible.
00:40:37
Speaker 1
So, obviously, you just don't want to do that.
00:40:40
Speaker 1
What you want to do is you want to have a thread sleeping, and the thread wakes up if there's new data there.
00:40:47
Speaker 1
So,
00:40:48
Speaker 1
So if this ADS has sampling rate, let's say of 10 hertz, then you want to have this the Raspberry Pi only, the thread only waking up, you know, 10 times per second and otherwise sleeping.
00:41:01
Speaker 1
And the way of doing this is by using a data ready pin of the ADC converter.
00:41:06
Speaker 1
So all new ADC converters have a data ready pin.
00:41:11
Speaker 1
So that's us firing at the sampling rate.
00:41:15
Speaker 1
And with that, you can wake up a thread and read the data.
00:41:19
Speaker 1
So for that, when the Raspberry Pi, you would use a GPIO for that.
00:41:25
Speaker 1
So with the GPIO, the GPIO would then wake up the thread, and then with that, you could read the ADC data.
00:41:36
Speaker 1
So why is that not moving forward here?
00:41:39
Speaker 1
Okay, so how does it work?
00:41:43
Speaker 1
Let me just before, so you see here for those who want to who want to also play around with that, so there's the lip lip GPIO event demo also on GitHub here again.
00:42:02
Speaker 1
Let me just go go here.
00:42:07
Speaker 1
I should be pressing pressing.
00:42:14
Speaker 1
Zoom is making this computer super slow.
00:42:17
Speaker 1
When I'm pressing a button here, it's taking ages until something is happening.
00:42:27
Speaker 1
Lib GPRO event demo.
00:42:29
Speaker 1
There we go.
00:42:29
Speaker 1
So I put this also in the chat for those who want to have a play with that.
00:42:38
Speaker 1
So lib GPRO event demo.
00:42:40
Speaker 1
It's a very simple example.
00:42:42
Speaker 1
I've got my Raspberry Pi also here.
00:42:45
Speaker 1
So I've just connected a button to the GPIO pin 27.
00:42:52
Speaker 1
So this photo here is not representative of a setup what I have here because Chong Feng has got my button and he still has it.
00:43:02
Speaker 1
So, therefore, the way it looks like here just now on my on my computer is here is here this one you see this is real, so and there's this very simple, just button here.
00:43:15
Speaker 1
Hopefully, you can see that I'm able to press that.
00:43:20
Speaker 1
And so, let's just let's just go back to this here.
00:43:26
Speaker 1
So if you want to do blocking IO, so we need to do blocking IO on GPIO pins.
00:43:33
Speaker 1
So how do we do that?
00:43:35
Speaker 1
So the Linux kernel provides a IO or just a library which is doing that.
00:43:41
Speaker 1
And that just now it's just basically on the version #2, which is slightly more complicated than the version #1, but it's a bit more structured.
00:43:53
Speaker 1
So in the
00:43:56
Speaker 1
So, OK, so what do we need to do?
00:43:59
Speaker 1
So, we need to 1st configure the I/O line we want to we want to work on.
00:44:07
Speaker 1
So, there's a there's a structure called GPRO line config, and there you're setting the pin number you would like to use.
00:44:16
Speaker 1
So, as I said, in this case it's twenty-seven, and then you're setting here's a here's a direction, obviously what we would like to have.
00:44:25
Speaker 1
Have this here as an input, and then, and then we would like to have the edge detection here and see, so when this button is pressed, so I just I just do detection if it's if it's pressed and released, you can obviously also change change it to other things here.
00:44:46
Speaker 1
I should just change it maybe back to presentation.
00:44:50
Speaker 1
Also note again the use of structs.
00:44:53
Speaker 1
So here, so this GPIO line config is a struct and then and then and then here you're setting basically here the settings here in this in this struct with this command here.
00:45:08
Speaker 1
That's a that's a very general practice nowadays to do it like this.
00:45:12
Speaker 1
So step #2 is then you're creating a so-called request for blocking IO.
00:45:19
Speaker 1
So, now it's now it's getting getting a bit it looks a bit a bit complicated here.
00:45:24
Speaker 1
So, first of all, you have to specify where this IO chip is in terms of IO device here.
00:45:36
Speaker 1
So, there's a there's a pseudo device on the Raspberry Pi.
00:45:41
Speaker 1
Now, let's just let's just let's just go on the on the Raspberry Pi.
00:45:49
Speaker 1
Hopefully that's still the IP address we have here.
00:45:54
Speaker 1
Yeah, we have that.
00:45:57
Speaker 1
So you see here there's a dev GPIO chip.
00:46:01
Speaker 1
So if I do here dev GPIO.
00:46:08
Speaker 1
Yeah, so you see here, so the Raspberry Pi has this, that's a Raspberry Pi 4.
00:46:14
Speaker 1
It has
00:46:16
Speaker 1
GPIO chip zero, GPIO chip one, and GPIO chip four, and so GPIO chip zero is the one we are after that are the ones which are on the primary header, and then and then and then what we're doing is here we are creating a shared pointer.
00:46:35
Speaker 1
To this to this chip here with this with this chip command here, and then and then there's a then there's a strange construction there which I personally don't understand why they really need that, but they just love that you are creating a so-called request on this chip that you want to want to do something with it.
00:46:59
Speaker 1
And then, and then you are configuring your line line with that with line config what we have done in step number number one, and then you're creating a request here again as a shared pointer, so this builder then generates request.
00:47:16
Speaker 1
So, this request is basically arming this GPO pin to do something with it, so, and then this the rest of the request
00:47:28
Speaker 1
will be obviously happening happening in our in our thread, because we would like to have a blocking IO in the thread, so then this step #3 is we have a then in our blocking IO in our thread here, we've got this blocking IO call here which is that, so request wait edge event and then we're also able to specify a timeout here if nothing has happened.
00:47:57
Speaker 1
And then, and then we are creating a callback here, GPIO event in this case here, and then we're going going back to sleep, so that's the idea behind behind that.
00:48:09
Speaker 1
So, let's just let's just see on the Raspberry Pi here if it's if it's actually working.
00:48:19
Speaker 1
I said here GPIO event demo, what's that one?
00:48:23
Speaker 1
Yeah.
00:48:27
Speaker 1
So I've already, again, for those who are trying it out, do cmake and make.
00:48:35
Speaker 1
I've already done this before.
00:48:39
Speaker 1
And so, and then there's a subdirectory called example here.
00:48:45
Speaker 1
And then, and then here there's the GPRO printer.
00:48:50
Speaker 1
So
00:48:51
Speaker 1
Let's just see if it's working.
00:48:53
Speaker 1
Yeah, it's working.
00:48:54
Speaker 1
Okay, you obviously can't see when I'm when I'm when I'm pressing pressing the button there, so that's the reason why I've got my camera set up here, actually actually seeing seeing what's happening here.
00:49:07
Speaker 1
Let's just start this from scratch, so that's my finger here, so you see, so we've got here falling, falling and rising.
00:49:20
Speaker 1
And so you see this works quite nicely.
00:49:25
Speaker 1
You see also that because this switch is probably quite old, rotten and corroded, because I got this from our electronics store on level 7 in the ranking building, it has loads of bouncing and we are getting not just rising and falling, but the Raspberry Pi is probably missing out on certain events.
00:49:47
Speaker 1
They are, that's the reason why we're getting suddenly 2 two rising and two falling and something like that, or 4 falling because it's just not able to catch the events in between there.
00:50:00
Speaker 1
Okay, so, how does it how does it does it work inside here?
00:50:07
Speaker 1
Let's just let's just have a have a look here again.
00:50:10
Speaker 1
That's what I just described here, so there's a header file GPRO event.
00:50:23
Speaker 1
So let's see, that's a header file summarizing this here.
00:50:27
Speaker 1
So you see here I'm defining A callback here, standard function.
00:50:33
Speaker 1
In this case here, I'm also as an argument transmitting the edge event that people can find out if it was a rising edge or falling edge.
00:50:42
Speaker 1
So I'm transmitting this in the callback.
00:50:45
Speaker 1
I'm also having an error callback in case something went wrong.
00:50:50
Speaker 1
And then here I've got the event callback to register this.
00:50:55
Speaker 1
And then here we have the worker.
00:51:00
Speaker 1
So let's just have a look what the worker does.
00:51:04
Speaker 1
The worker is defined here in the CPP file.
00:51:11
Speaker 1
So, you see here we start function with all this, what I've talked about, and you see this is basically what the worker is doing here as far as after the request has been has been has been started here via the start function, then here we have we have here so the blocking function here, and then and then and then when this is here successful.
00:51:39
Speaker 1
Then we are calling this here this GPRO event.
00:51:42
Speaker 1
Remember this GPRO event is standard function here.
00:51:46
Speaker 1
So I've used the, let's just get out here.
00:51:52
Speaker 1
I've used here again approach number one.
00:51:57
Speaker 1
So here the event callback.
00:52:02
Speaker 1
Where's my standard function?
00:52:04
Speaker 1
There.
00:52:05
Speaker 1
So
00:52:06
Speaker 1
So that's my standard function here.
00:52:11
Speaker 1
And then this is defined here.
00:52:13
Speaker 1
So if I go into the example, so in the example here, that's my GPRO printer.
00:52:27
Speaker 1
So here, this is my event printer class.
00:52:31
Speaker 1
So that's the subscriber in this case here.
00:52:34
Speaker 1
So the subscriber I'm defining here has event.
00:52:38
Speaker 1
This matches up with my definition of a standard function.
00:52:43
Speaker 1
And then I'm looking here at the type of event, and then I'm able to print out here the rising edge or falling edge.
00:52:52
Speaker 1
So that's just basically what I'm doing here.
00:52:54
Speaker 1
And now here again, we have here this thing here.
00:52:58
Speaker 1
So we have got the event printer.
00:52:59
Speaker 1
That's our subscriber.
00:53:01
Speaker 1
And then the GPIO pin here is our publisher.
00:53:05
Speaker 1
And that's again the glue between them with a beautiful lambda function.
00:53:09
Speaker 1
Again, you see capture and sign.
00:53:13
Speaker 1
And in this case here, there's an argument here of lambda function because it's the event which is transmitted.
00:53:21
Speaker 1
And then this is printed out here in the event printer class.
00:53:28
Speaker 1
So, you see, it's a pretty pretty simple concept once you're getting getting head to head around that.
00:53:35
Speaker 1
And so, let's just go back to this here.
00:53:43
Speaker 1
Yeah, so just as a just as a slight a lot of bullet points here.
00:53:49
Speaker 1
So, if you just see here in the GPO code example, so there's no sleeper pulling in there.
00:53:56
Speaker 1
Yeah, so
00:53:58
Speaker 1
the actual worker is only running with blocking IO.
00:54:03
Speaker 1
the only if there's anything sleeping, then it's the main program, so there's a get character in there.
00:54:11
Speaker 1
So the complexity is hidden away in the C class.
00:54:15
Speaker 1
So all this nasty stuff with request and something like that is all inside of this C class there.
00:54:23
Speaker 1
So we have start and stop functions.
00:54:25
Speaker 1
which are starting the thread and terminating it.
00:54:29
Speaker 1
So we have no explicit memory allocation in there.
00:54:32
Speaker 1
So we have no new and delete in there.
00:54:36
Speaker 1
And so any memory allocation is managed by the standard template library and lib GPOD itself.
00:54:43
Speaker 1
So as you see, I've used smart pointers to avoid this.
00:54:48
Speaker 1
And obviously CMAC build system, it's compulsory also in this class.
00:54:54
Speaker 1
so the GPIO class I've defined as a library, so just to make it recyclable for other parts of a program.
00:55:06
Speaker 1
There's debug output, which depends on the CMag build style.
00:55:10
Speaker 1
The debug is printed out if CMag is compiling a deep program in debugging mode.
00:55:17
Speaker 1
So
00:55:18
Speaker 1
has all compiler errors enabled, so I would recommend that you are also enable all compiler errors to make your code really, really stable and nice.
00:55:28
Speaker 1
And there are also doc strings for doxygen in there, so if you, if you're, if you're, if you're, if you're looking, looking here at the, especially at the GPO event header file, you see here
00:55:47
Speaker 1
that I've have comments everywhere in here describing basically what these what these different functions or types types doing here, so and then and then just a read me with some instructions with clear instructions how to build and how to use it, so that's just basically also what I'm expecting from your projects.
00:56:13
Speaker 1
Okay, so we're running out of time.
00:56:18
Speaker 1
So, next time what we're doing is, so we're looking at other blocking IO, obviously not just GPIO, so video on Linux is blocking IO, so it's wakes up after every every frame, for example.
00:56:33
Speaker 1
Audio is blocking IO, Bluetooth is blocking IO, I square C is not really blocking IO, so we need to need to combine it with GPIO.
00:56:47
Speaker 1
And it's the same thing for SPI.
00:56:50
Speaker 1
SPI is also not blocking RO and so we also need to combine this with GPIO.
00:56:56
Speaker 1
So if you're using chips using R square C and they're generating events, then you need to have a data ready pin for that.
00:57:04
Speaker 1
And it's the same thing for SPI.
00:57:07
Speaker 1
Okay, so that's us, that's us all for today.
00:57:12
Speaker 1
Apologies for the slight rough start, because I was just rushing from another event in here for the lecture.
00:57:19
Speaker 1
So, and but this is the most important part, probably in terms of coding that you're making that you're making sure that you understand these two concepts as using either using standard function or callback interfaces to do communication between classes.
00:57:40
Speaker 1
And I think once you have
00:57:42
Speaker 1
digested that, then the rest is pretty easy.
00:57:47
Speaker 1
So that's just one of the most important aspects of this class to see how this translates into user space.
00:57:55
Speaker 1
Okay, great.
00:57:55
Speaker 1
So I am wishing everybody a nice evening, and I see you next week at the pitching session.