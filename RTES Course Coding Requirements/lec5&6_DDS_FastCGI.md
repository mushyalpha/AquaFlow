00
Speaker 1
on recording on this computer here.
00:00:08
Speaker 1
OK, so today it's going to be a it's the last bits and bobs from this from this lecture here.
00:00:16
Speaker 1
So it's a that's the final the final one about content.
00:00:20
Speaker 1
Next week I'm only going to talk a bit about the assessment criteria that you know basically what's this what you need to
00:00:29
Speaker 1
need to be aiming for to get good marks.
00:00:31
Speaker 1
And so today it's just talking about if you are communicating between 2 Raspberry Pis or between a PC and a Raspberry Pi, so how to do that.
00:00:48
Speaker 1
So hopefully you can hear me via the audio here.
00:00:53
Speaker 1
So today we are talking about
00:00:57
Speaker 1
publisher and subscriber stuff.
00:00:59
Speaker 1
So, remember, so far, let me get the slide showed here.
00:01:06
Speaker 1
So, far we've been talking, we've been basically communicating on the same computer.
00:01:13
Speaker 1
So, we had one Raspberry Pi, and on this Raspberry Pi, we had callbacks and setters and between classes.
00:01:21
Speaker 1
So, that's all pretty easy.
00:01:24
Speaker 1
And so,
00:01:25
Speaker 1
So, the question is now, basically, what do we do if we don't have the same computer, but we do communication between 2 computers?
00:01:35
Speaker 1
So, how do we how do we deal with that?
00:01:37
Speaker 1
And, obviously, because the class is called real-time real-time coding, so we need to have some kind of transmission protocol between computers, where the transmission is real-time and we can transmit data between that.
00:01:55
Speaker 1
And so far, just in terms of recap here, you can think of that, what we have been doing in this class here, like a publisher subscriber framework.
00:02:08
Speaker 1
So we have sensor events coming in, so just readings or something like that.
00:02:14
Speaker 1
And we have a C low-level sensor class, which gives us readings from a sensor at a certain sampling rate or certain events.
00:02:25
Speaker 1
And then we have callbacks going to different classes here.
00:02:29
Speaker 1
So here, as you know, we're gluing these together with lambda functions.
00:02:33
Speaker 1
So in a lambda function here, you cannot just put in one call in there, but you can put a lot of calls in there to two different classes.
00:02:42
Speaker 1
And so therefore, you can have one event going to these three.
00:02:47
Speaker 1
So we have a publisher here and we have a subscriber here.
00:02:50
Speaker 1
So that's us all on the same.
00:02:53
Speaker 1
on the same computer.
00:02:54
Speaker 1
But so how do we do that?
00:02:55
Speaker 1
Basically, if you have two Raspberry Pis, for example, I have one of these here.
00:03:03
Speaker 1
That's actually my video here.
00:03:06
Speaker 1
I cannot see my own camera here.
00:03:12
Speaker 1
Hopefully, hopefully this works.
00:03:14
Speaker 1
So there's one Raspberry Pi and imagine you have another Raspberry Pi here.
00:03:17
Speaker 1
I've got lots of Raspberry Pis lying about.
00:03:21
Speaker 1
So, you would like to do have to do a communication between between two of these guys here.
00:03:29
Speaker 1
So, we have we have a Raspberry Pi here, so we have events coming in and we want and then we have another Raspberry Pi which which receives the events and what we want to do first is
00:03:44
Speaker 1
We want to talk about, so what do we do in a local network?
00:03:47
Speaker 1
So, like here at home, I've got one network with a subnet, you know, it's similar what you have in the lab, 100, you know, what we have here, the Raspberry Pi, and the one is on 1921681.1.1121, and the other one is at 100 ninety-two 1681.30, so the same subnet.
00:04:14
Speaker 1
So basically what you would have in a home network, you have one subnet and then you have all different kinds of devices connecting to that.
00:04:23
Speaker 1
And so how can you make them talking to each other that they see each other and do real-time communication without any hassle?
00:04:34
Speaker 1
So I have a local network, so they're both plugged in into my network via Ethernet cable.
00:04:40
Speaker 1
and we want to have them talking to each other.
00:04:43
Speaker 1
So there's an event coming in here.
00:04:45
Speaker 1
And then obviously we have on the other Raspberry Pi a callback interface here.
00:04:52
Speaker 1
Spelling check again.
00:04:53
Speaker 1
Callback via callback interface.
00:04:56
Speaker 1
Okay, so how do we do this?
00:05:01
Speaker 1
So the, you know, the way the transmission protocol for this kind of stuff
00:05:08
Speaker 1
is usually done nowadays via so-called data distribution service.
00:05:14
Speaker 1
So we have a local network here, like this cloud here in the middle, and then we have a message here.
00:05:22
Speaker 1
So whatever, for example, like new temperature reading, it's now 20 degrees in this room here.
00:05:28
Speaker 1
Then we have a publisher, and then this publisher publish a network via something called topic.
00:05:35
Speaker 1
So this topic may be
00:05:37
Speaker 1
you could just call this topic temperature, so, and then and then the network and just blast it into the network here, and then and then somewhere else in the network we have subscribers, so other Raspberry Pi's, and they and they then have a have a call back here, so, and this and this call back subscribes.
00:05:58
Speaker 1
To this to this topic here, so if you call this topic here, for example, temperature, then this then this subscriber here subscribes to temperature, and then and then when there's a new temperature reading is released, then there's a callback here at the other end on the other Raspberry Pi, and then and then this can be dealt with there.
00:06:17
Speaker 1
So, we have some more like, you know, still a callback framework, but it's basically between two two computers, you know, so you can also do this
00:06:27
Speaker 1
Obviously, on your laptop PC, not just on the Raspberry Pi, you can do it, you know, on all different kinds of devices.
00:06:34
Speaker 1
So, here you see there's another topic here, topic #2, and then this maybe could be pressure or something like this, and then if you call this topic here pressure, then this will be published here from this sensor.
00:06:50
Speaker 1
transmitted blast in the network, and then anybody who subscribed to this pressure topic here would get a call back with that.
00:06:57
Speaker 1
So, that's the idea behind this.
00:07:01
Speaker 1
So, how do we how do we do this more practically here?
00:07:06
Speaker 1
For this purpose, we used we used a transmission protocol which is called Fast DDS.
00:07:14
Speaker 1
Yeah, so Fast DDS
00:07:16
Speaker 1
It's a data distribution service, so that's a middleware protocol, and then there's an API defined by a group called the Object Management Group, which is obviously an amazing abbreviation, OMG.
00:07:32
Speaker 1
Yeah, and the data is defining basically how this how this protocol is defined.
00:07:37
Speaker 1
Yeah, so this protocol is used in ROS 2, so in the robotic operating system.
00:07:44
Speaker 1
obviously in robotics you need to have real-time response.
00:07:49
Speaker 1
It's also used in automotive and it's recommended there by Autosar.
00:07:55
Speaker 1
So it has low latency data connectivity.
00:07:59
Speaker 1
So it's designed that has low latency there.
00:08:02
Speaker 1
That's in contrast to all the other protocols you might know.
00:08:06
Speaker 1
like MQTT, HTTP, TCPIP, and something like that.
00:08:11
Speaker 1
So you can get a latency guarantee in the protocol, and obviously we want that for real-time processing.
00:08:18
Speaker 1
The other amazing thing is it's so it does auto-discovery.
00:08:22
Speaker 1
So if you have different Raspberry Pis or computers in a network, they will automatically find each other.
00:08:28
Speaker 1
So there's no need to specify IP addresses or any kind of awkward stuff.
00:08:33
Speaker 1
So as long as the
00:08:34
Speaker 1
as the device is living in the same subnet, so then they will find each other.
00:08:40
Speaker 1
So, therefore, if you have a Wi-Fi network also, like the one at university or also at home, the device would automatically find each other on this network there, which is fantastic.
00:08:54
Speaker 1
So, we don't need to deal with these things, specifying IP addresses, hard-coding them somewhere, or having configuration system to put them in.
00:09:04
Speaker 1
So, it's done all automatically there, so it's defined as being very reliable, so or specified as reliable, so it's so it's not like UDP where you might lose connections or something or data.
00:09:22
Speaker 1
There's loads of loads of more features out there you can delve into fast DDS.
00:09:30
Speaker 1
As deep as you as you as you like, where's my where's my browser?
00:09:35
Speaker 1
There, let's have a look.
00:09:38
Speaker 1
Browser is again super super slow here, fast DDS, so you can obviously delve delve into this here and have a have a have a look yourself.
00:09:59
Speaker 1
About this protocol here, it's there are different companies providing this protocol here, so this company is one of the major company companies which are which are providing this, and this is also provided on your Linux system, so therefore there are already packages on your Linux system, you know, offering you fast DDS.
00:10:27
Speaker 1
So, we are coming already we are we are coming coming back to this a bit later, but so if you where's my Raspberry Pi here?
00:10:36
Speaker 1
So, if you go to your to your Raspberry Pi, and so if I if I go here into the package management management system, I recommend everybody using deselect, by the way, if you haven't.
00:10:54
Speaker 1
done this done this already here, so you see here there's the fast DDS generation tool, and then you see there's a lib fast DDS development library already there, so you just so you just select that and off you go and you can work with this fast DDS on your on your Raspberry Pi, so it's already all there as a package.
00:11:16
Speaker 1
So, as you see, three stars here it's installed on my on my Raspberry Pi here, so we're going to use it there.
00:11:23
Speaker 1
in a bit.
00:11:27
Speaker 1
OK, so let's just get a get a terminal here out of out of the out of the way again.
00:11:35
Speaker 1
OK, so, fast DDS, so it's so it's data-centric, yeah, so it's not message-centric like MQTT or MTCP/IP.
00:11:47
Speaker 1
Data-centric means you are actually defining the data which is transmitted, so the structure basically what is inside there.
00:11:56
Speaker 1
And it's strongly typed.
00:11:59
Speaker 1
So this means you're really specifying, you're transmitting a string, an integer, or two strings, an integer, an array, or something like this.
00:12:08
Speaker 1
So therefore, again, it's a very safe way of transmitting.
00:12:12
Speaker 1
So it's not like MQTT or something like this or even worse TCP/IP where you're just transmitting essentially a text file and then you need to pass it and there just might be might be errors on the receiving end.
00:12:25
Speaker 1
So in this case, if you're specifying, you know, just your fast DDS packet, you know, then this will be automatically matched up on the other side.
00:12:37
Speaker 1
So how do we how do we do this?
00:12:40
Speaker 1
So
00:12:41
Speaker 1
So, in fast DDS, you need to create your message, and the message is defined in a so-called message in a so-called interface description language.
00:12:53
Speaker 1
So, here, Hello World message IDL.
00:12:56
Speaker 1
So, if you're writing a fast DDS program, you need to specify a file called with the ending IDL, and as you see, it looks
00:13:07
Speaker 1
Pretty much, much like in our C file or C or header file, you are defining a structure and then the structure contains different different data types.
00:13:20
Speaker 1
So, you see here there are certain certain data there, there's a list of data types allowed and disallowed you have to go on the website of this company, what I just told you, or on the definition page of FastDDS.
00:13:33
Speaker 1
which types are allowed.
00:13:35
Speaker 1
What you see is the basic types are obviously allowed, like for example, unsigned integer, or was also allowed is a C++ style types like a string, for example.
00:13:50
Speaker 1
So, you define you define this Hello World message here.
00:13:56
Speaker 1
So, if I go back here to my fast DDS demo,
00:14:06
Speaker 1
I should say before I forget that, because for those who want to have a play with this, where's my of course, as always, there's the example code on my GitHub here for this.
00:14:25
Speaker 1
I must say it's
00:14:30
Speaker 1
It compiles only on the Raspberry Pi just now in this format here, because the if you're using if you're using your desktop computer, it might not it might not compile because these are packages on desktop system like Ubuntu is a bit outdated just now.
00:14:49
Speaker 1
You can also get this get this to compile, but you need to change change a bit of the of these dependencies here just as a warning, but on the Raspberry Pi this code here works.
00:15:00
Speaker 1
So if you have two Raspberry Pis or something like that, works.
00:15:04
Speaker 1
If you want to run it also on a laptop, you have to modify this slightly.
00:15:08
Speaker 1
I can help you with that in the class.
00:15:11
Speaker 1
But I have basically changed it to this new format.
00:15:15
Speaker 1
Anyway, so the code is here.
00:15:18
Speaker 1
And so therefore here there's a hello world message IDL.
00:15:23
Speaker 1
So this is here defined.
00:15:26
Speaker 1
Here, I'm transmitting an index number and a message, so that's just an example here in this transmission transmission protocol, and so in this message message format, where's my terminal for that?
00:15:40
Speaker 1
Yeah, so if I if I go in here, so you see there the Hello World message IDL here.
00:15:53
Speaker 1
So, that's just that's just here.
00:15:55
Speaker 1
So, this IDL is obviously not usable to you can't you can't compile that, but the way as a next step, what you have to do is, yeah, so you take this Hello World message IDL and use a program called Fast DDS Gen Hello World message IDL and you run this program and then this generates you
00:16:23
Speaker 1
these C C files here out of this.
00:16:26
Speaker 1
So you see there's a C C files is called you CXX then a header file which is called has the ending HPP and then another file here.
00:16:39
Speaker 1
So these ones need to need to include in your program and then and then and then these messages are available in your in your in your program here.
00:16:49
Speaker 1
So obviously because I'm.
00:16:53
Speaker 1
I'm using, I'm using CMake, I'm doing, I've automated that here, fast DDS gen, that's the IDL, so if I, if I, if I do that, it should, it should do this here, so you see, you know, then this generating generating these files, it's saying here they already exist, so, they are now basically here.
00:17:20
Speaker 1
But of course, I'm like all of you, must be creating a C make C make file as a build system and the and so and so they are here what I what I do in the C make file here in order to build the whole the whole project here I'm adding a custom target here and this custom target here then automatically executes executes here this fast EDN.
00:17:48
Speaker 1
fast DDS gen here, and so this custom target here is called messages.
00:17:53
Speaker 1
And then I'm at this here as a dependency to this library here, which is creating basically a library file here for the messages.
00:18:04
Speaker 1
So that's also the way I strongly recommend this to you if you are working with fast DDS, that you're creating something like that in your own program and creating basically the message
00:18:17
Speaker 1
here for the message or messages as a library, and then you can link the library into your different different other parts of your of your program, so, and especially in the subscriber in the publisher.
00:18:32
Speaker 1
So, let's see, so you see here, you know, this then creates here this static library here, and then the code for the messages inside here.
00:18:47
Speaker 1
Okay, so what do we do now actually in the publisher and subscriber part there?
00:18:56
Speaker 1
So in the publisher, it's obviously easy.
00:18:59
Speaker 1
In the publisher, we have just a method inside there called publish.
00:19:06
Speaker 1
So price, yeah, and the publish message has here just a hello world message here, hello inside.
00:19:15
Speaker 1
remember this consists here of index number and the message of sorry of a string, and then and then this will be just here written with the right command, and then this will be basically published published by this by this operation here, so, nothing exciting.
00:19:34
Speaker 1
If we go into this program here, where are we?
00:19:41
Speaker 1
So, here there's a there's a publisher.
00:19:44
Speaker 1
There's obviously a lot more code in there, but so you see there's a hello world publisher class here.
00:19:51
Speaker 1
Then there's a data writer stuff here.
00:19:54
Speaker 1
There's a callback here.
00:19:56
Speaker 1
If there's actually a subscriber matched and other stuff here, but then but then here you see this is a function I just talked about here.
00:20:09
Speaker 1
There's a publish function here.
00:20:11
Speaker 1
and then this goes out here.
00:20:13
Speaker 1
So, in this demo program here, just to just to publish something a few times here in this demo program, I'm just using a timer here, and the timer publishes then every second the message Hulu and an index number here.
00:20:31
Speaker 1
So, that's a that's the whole thing, what this what this what this program does.
00:20:37
Speaker 1
Just we are coming back to this.
00:20:39
Speaker 1
So, the subscriber, so the one which is receiving receiving the data, that is obviously written as a callback, so now we need to implement on the receiving side a callback, and this callback is done not with standard function, what I talked in the previous lectures about, but today we are using as a callback implementation.
00:21:09
Speaker 1
abstract functions.
00:21:10
Speaker 1
So remember we also talked about that before.
00:21:13
Speaker 1
So here is this magic keyword override.
00:21:16
Speaker 1
So this means that this data reader listener class here, what we are inheriting into the sub listener here, has an abstract class on data available, which is undefined in data reader listener.
00:21:31
Speaker 1
So it's abstract.
00:21:32
Speaker 1
And then here with the override, we're overriding this here and putting our code in there for the message, what we want to deal with that here.
00:21:42
Speaker 1
So we see in this case here, so we're getting a message in this callback.
00:21:48
Speaker 1
And then here as a simple thing here, if the data is valid, we just print it out.
00:21:53
Speaker 1
So there's nothing more we do here.
00:21:56
Speaker 1
So just to have a demo that this printing is happening here.
00:22:03
Speaker 1
And so, before we summarize that, so let's just let's just let's just go go back here to the code.
00:22:14
Speaker 1
So, where's the subscriber?
00:22:17
Speaker 1
Yeah, so there's the hello world subscriber here, and then within the hello world subscriber here, we've got the got the listener class.
00:22:27
Speaker 1
Remember, listener class is where
00:22:30
Speaker 1
is where the receive function is overridden.
00:22:37
Speaker 1
So here on data available, that's a callback.
00:22:40
Speaker 1
Then this is overridden here, and we're printing out the message here.
00:22:44
Speaker 1
There's, by the way, another callback here, which is quite useful here, on subscription matched.
00:22:51
Speaker 1
This just means basically that there's actually a publisher out there, and this callback is called that actually they are now matched to each other, so that we have a match between the publisher and the subscriber.
00:23:08
Speaker 1
So, and obviously, so we don't need to implement that necessarily, but it's very good to know.
00:23:15
Speaker 1
that just happened, so there's another callback here on subscription matched.
00:23:19
Speaker 1
Callbacks are very often in the coding world called on something, because there's obviously something when something is happening.
00:23:27
Speaker 1
So there's an event happening here that we have a match to a publisher.
00:23:33
Speaker 1
So obviously, just a bit of other housekeeping functions in there, just, you know, go through your
00:23:42
Speaker 1
So the stuff by yourself here you see great topic.
00:23:46
Speaker 1
That's the topic what I told about here.
00:23:48
Speaker 1
So hello word and then there's a message inside.
00:23:52
Speaker 1
We have to create a subscriber and we have to create a data reader.
00:23:56
Speaker 1
And then and then the main program is basically as any event-driven program should do is it's doing absolutely nothing in the main program.
00:24:07
Speaker 1
That's also your goal for your final final program.
00:24:10
Speaker 1
For whatever program you are writing, at the end, I don't want to see anything doing happening in the main program, and then the rest is just dealt with in the callbacks here.
00:24:24
Speaker 1
So let's just see if this is actually working.
00:24:28
Speaker 1
So where are we?
00:24:30
Speaker 1
Where's actually this thing here?
00:24:32
Speaker 1
There's a clock here.
00:24:33
Speaker 1
I should actually have it here.
00:24:38
Speaker 1
So here we have the one Raspberry Pi.
00:24:43
Speaker 1
So mine G and Git.
00:24:45
Speaker 1
So let's see.
00:24:47
Speaker 1
So that's the Raspberry Pi here at this address, 192.168.1.30.
00:24:56
Speaker 1
That's A Raspberry Pi which is sitting here on my shelf.
00:25:00
Speaker 1
That's my basically my mini server for stuff
00:25:05
Speaker 1
to do at home if I need to do development on the Raspberry Pi, that's always on.
00:25:11
Speaker 1
And then I've got the other Raspberry Pi, which is just called Raspberry Pi, which is here on my desk.
00:25:18
Speaker 1
So let's see.
00:25:19
Speaker 1
So let's see the IP address of this one here is 1921681.121.
00:25:28
Speaker 1
As you see here, because I have a proper internet service provider,
00:25:33
Speaker 1
I have also internet 66 addresses here.
00:25:37
Speaker 1
That is absolutely horrible constructs.
00:25:39
Speaker 1
Anybody who might be at Glasgow University is not offering internet version 6 addresses here, but here at home I've got also an IP IP version 6 address, which is a lot longer here than this humble, humble address here up here.
00:25:58
Speaker 1
A lot, a lot more addresses available here than...
00:26:02
Speaker 1
you see the other Raspberry Pi also has that.
00:26:05
Speaker 1
Yeah, so even putting this number into anything manually is already just an absolute pain.
00:26:12
Speaker 1
So better the systems are able to do it by themselves.
00:26:19
Speaker 1
Okay, so let's just start now here on the one Raspberry Pi, the publisher, and then let's start on the other one here.
00:26:30
Speaker 1
the
00:26:31
Speaker 1
subscriber.
00:26:32
Speaker 1
Hopefully this works.
00:26:35
Speaker 1
So let's start the publisher.
00:26:37
Speaker 1
I know that's or first the subscriber, I don't know.
00:26:40
Speaker 1
Okay, starting subscriber, publisher.
00:26:44
Speaker 1
So you see now, they are saying publisher is matched and subscriber is matched.
00:26:51
Speaker 1
And then as I said, the only thing what this thing is doing is sending
00:26:55
Speaker 1
sending a string string over called Hulu and the index and the counter here counting up from 1:00 to 10:00, and you see this is also arrived arrived here at the other end.
00:27:09
Speaker 1
So, it's a really nice transmission protocol for local networks because you really don't need to deal with nasty IP address matching or something like that.
00:27:21
Speaker 1
The you know, as you see, they're finding each other.
00:27:24
Speaker 1
So, and this works super reliably, and as I said, the this kind of transmission protocol DDS is used is used now in the robotic operating system version two, so that's a standard transmission protocol between different different devices.
00:27:50
Speaker 1
So, in ROS 2, by the way, it's
00:27:52
Speaker 1
It's even used on the same computer.
00:27:55
Speaker 1
And the reason is because ROS 2 allows coding in C and Python.
00:28:02
Speaker 1
That's obviously not very, very compatible.
00:28:04
Speaker 1
And in ROS 2, essentially all the communication is then done between, you know, via this middleware, then it allows all the communication between different coding languages.
00:28:16
Speaker 1
And it's also these advantages, and it doesn't matter where the software runs.
00:28:19
Speaker 1
So therefore, if you're realizing
00:28:22
Speaker 1
your single computer is too slow, then you can easily distribute your work on more than one computer.
00:28:28
Speaker 1
So it's very often happening nowadays on robotic platforms that you have maybe a small Raspberry Pi doing the direct IO operations and the really low-level motor control stuff.
00:28:40
Speaker 1
And then you have on top of this a mini laptop sitting inside of the robot.
00:28:45
Speaker 1
And then the laptop is connected with the Raspberry Pi via DDS.
00:28:50
Speaker 1
And then you can offload the more high high high computing demands on the other on the other computer there.
00:28:58
Speaker 1
so it's there are lots of other tricks going on to make it make it fast, or if fast EDS realizes it's running on the same computer, it's actually only implements A callback, you know, so surprise.
00:29:13
Speaker 1
So there's actually no internet communication happening happening at all.
00:29:17
Speaker 1
So yeah, but it's real time, it's safe.
00:29:20
Speaker 1
and you don't need to specify any IP addresses there.
00:29:26
Speaker 1
So, that's the that's the first part.
00:29:29
Speaker 1
So, he was wondering what's happening in the other 30 minutes, so I'm switching switching to another to another to another lecture, because obviously sometimes it is it is so that we that we
00:29:50
Speaker 1
Where is this thing now?
00:29:51
Speaker 1
That we also have to have to communicate further, further, further afield.
00:29:57
Speaker 1
It just gets this lecture, lecture out here.
00:30:07
Speaker 1
because we have to we have to also communicate further further further afield that so imagine you have your Raspberry Pi somewhere somewhere running and you would like to have a website and that everybody in the world can just view this website and view real-time data on it and interact with that.
00:30:32
Speaker 1
And so, the question is, so what do we do if we have and if you want to not just have something local network, but we want to have it somewhere?
00:30:41
Speaker 1
so, and that's obviously then you have to create a web server and the Raspberry Pi is can happily do this, so Raspberry Pi can easily be turned into a web server.
00:30:54
Speaker 1
So, my Raspberry Pi sitting here on my shelf is also running as a web server, and so we can
00:31:02
Speaker 1
See how this works, and then, and then the question is, basically, so how do we do the communication between the web server and the C application?
00:31:11
Speaker 1
So, how do we how do we actually link it together?
00:31:17
Speaker 1
So, and the example here is that we're using the web server NGIX or new generation XI think how it's how it's called officially by the developers.
00:31:29
Speaker 1
So how is this web server is able to communicate with your C application?
00:31:35
Speaker 1
And there's a very old, or has been invented very early, something which is called CGI, which is able to create an interface between a C application and the web server.
00:31:50
Speaker 1
So we need to talk about this.
00:31:52
Speaker 1
And then on the other side, we have, at the other end, the website,
00:31:58
Speaker 1
so on the website, then we have a, in the website itself, we have something like JavaScript running, and the JavaScript will be querying then data from the web server, which in turn then talks to the C application.
00:32:18
Speaker 1
So, we need to talk about that, how to do this in a real-time way.
00:32:24
Speaker 1
Also, we might have buttons on the
00:32:27
Speaker 1
on the website and the buttons, they are transmitting also events into the web server.
00:32:33
Speaker 1
So we need to talk about that.
00:32:37
Speaker 1
So how do we transmit data on the website, on the web, and the most popular data format there?
00:32:48
Speaker 1
is called JSON.
00:32:50
Speaker 1
So JSON is a very simple data format.
00:32:53
Speaker 1
You have curly brackets, then a key, like temperature, for example, 20, maybe just integer value steps, or just a string, all good.
00:33:06
Speaker 1
So you can transmit that.
00:33:08
Speaker 1
And the format is like that.
00:33:09
Speaker 1
So it's very, it's very simple.
00:33:11
Speaker 1
So essentially it's a text text file.
00:33:14
Speaker 1
with a special syntax inside here.
00:33:17
Speaker 1
So that's the way it looks like.
00:33:22
Speaker 1
So web servers, there are gazillions out there.
00:33:27
Speaker 1
So we need to obviously install one of them on the Raspberry Pi.
00:33:31
Speaker 1
So I'm using NGINX, which is, I think, the most robust and the most easy to configure one.
00:33:41
Speaker 1
Of the web servers, and it's very flexible, and again, you're getting you're getting modules or packages for your Raspberry Pi, so you don't need to download anything.
00:33:53
Speaker 1
You just select the package and NGINX is there, and so if you go here on the Raspberry Pi, oops, deselect.
00:34:09
Speaker 1
Again, as I said, use use deselect for package management if you haven't if you're not really doing it, so it makes your life life pretty pretty easy.
00:34:19
Speaker 1
Which Raspberry Pi am I here just now?
00:34:23
Speaker 1
NGINX edit.
00:34:30
Speaker 1
You see that that's all not installed here, gazillions of different
00:34:36
Speaker 1
different NGI and X modules available here.
00:34:40
Speaker 1
I'm just wondering where actually where actually the actual server is because and so, but you see the NGI and X here as a package there installed available.
00:34:56
Speaker 1
Yeah, so there's also the one of the earliest one is the Apache web server.
00:35:01
Speaker 1
Apache is, you know, is super hard to configure.
00:35:05
Speaker 1
It's also available on the Raspberry Pi if you're up for that.
00:35:11
Speaker 1
Then there's somewhat like a lighter version of the Apache, which is called, has similar syntax, which is called light TPD.
00:35:19
Speaker 1
And then there's a Java or JavaScript based server.
00:35:24
Speaker 1
Please don't use ever this in this class because it's JavaScript and you're going to have trouble talking to your C program.
00:35:33
Speaker 1
And then, obviously, the same thing is for Python-based servers like Flask, Django, Pyramid, or Bottle, or whatever they're all called, and you won't be able to talk to your C program with that.
00:35:46
Speaker 1
So, I would recommend use the NGINX web server if you need one.
00:35:53
Speaker 1
That's the easiest one to configure, and or the example, the example what I'm providing here is for the NGINX.
00:36:03
Speaker 1
OK, so let's us let's us go back to this to this glue.
00:36:07
Speaker 1
So, we so we have the NGNX here and we have the C application here where there's some event-based stuff is happening here, and so the glue is this is this so-called CGI handler.
00:36:23
Speaker 1
Yeah, so the CGI handler is again again a library under Linux.
00:36:28
Speaker 1
You can use
00:36:29
Speaker 1
And the CGI handler creates the glue between C application and the web server there.
00:36:39
Speaker 1
So, I'm going to show you this in a minute how this looks like in an example.
00:36:44
Speaker 1
So, I've also written example code for that, because it's again non-trivial to do that.
00:36:55
Speaker 1
So, if you go here back to my
00:37:00
Speaker 1
repository, also fast.
00:37:06
Speaker 1
We are only fast today, fast CGI.
00:37:10
Speaker 1
So that's here the example code you can have a look at.
00:37:19
Speaker 1
So you see that's the same diagram here, what I used in lecture here.
00:37:25
Speaker 1
So the only thing what you need to install of the packages here is the CGI library and the JSON library because we're transmitting in JSON.
00:37:37
Speaker 1
And then we're just transmitting the core part of the NGI in X.
00:37:41
Speaker 1
That's the one I was looking for when I just went to the package manager.
00:37:44
Speaker 1
So if you install the core, then that's enough what you need of the web server.
00:37:49
Speaker 1
There are gazillions of extensions there.
00:37:55
Speaker 1
And so, let's just go go and go back here to the to this one here, yeah.
00:38:05
Speaker 1
So, fast CGI, so I've so what I've written is I've written a fast CGI library is plain C.
00:38:14
Speaker 1
It's pretty it's pretty nasty to interface what I've written is somewhat like a wrapper orient C around this.
00:38:23
Speaker 1
So the fast CGI API low level one has again blocking IO as we as we want.
00:38:29
Speaker 1
So we have blocking IO and a thread which needs to be woken up.
00:38:33
Speaker 1
So and they are and the and that has that has two events which are coming coming coming from the fast CGI library.
00:38:44
Speaker 1
and it's always client-based, so your web browser triggers the whole thing.
00:38:51
Speaker 1
It's always originating from the browser.
00:38:54
Speaker 1
So we have two callbacks.
00:38:56
Speaker 1
So the one is the client request data.
00:38:59
Speaker 1
So that's a classical thing.
00:39:01
Speaker 1
When you open your web browser and you're going on this, you are requesting.
00:39:07
Speaker 1
some kind of web content, or in this case, we are requesting data.
00:39:11
Speaker 1
The other thing is you are sending data.
00:39:13
Speaker 1
So you also know that when you're going in a web browser and you're pressing a button saying pay for my eBay thingy or something like this, and then the button will send a request to the web server and transmitting some data.
00:39:28
Speaker 1
So like the button press or a number or just a few things together.
00:39:32
Speaker 1
so, all events are generated by the client, by the web browser.
00:39:37
Speaker 1
so the data format is usually JSON in this one.
00:39:44
Speaker 1
So, on the before I go into the JavaScript here, let's just go back to the oops, I'm using using the browser here.
00:39:55
Speaker 1
So, if I
00:40:00
Speaker 1
Let's just let's just go here into the into the code here, so I've so I've written this header file here, which is basically like a wrapper around this quite nasty, you know, C library, as I said, which is using blocking RO, and inside here I there's a there's a get callback here, yeah, so the callback handler needs to be implemented.
00:40:27
Speaker 1
and provides JSON a JSON string here.
00:40:31
Speaker 1
And again, remember I've defined this here as an abstract interface via this callback class here.
00:40:39
Speaker 1
So this one is 0, and then and then here there's a there's a post callback here.
00:40:45
Speaker 1
So if the if the browser posts some data back, for example, like a like a button press and so.
00:40:54
Speaker 1
And then, here in the start in the start part here, I'm populating the get and post callbacks here, and then and then the starting the whole thing.
00:41:06
Speaker 1
You can have a look here in the API header file if you want to have a look into the inner workings here, but as I said, I've written this a way that you don't need to need to worry about this because it's quite a lot of nasty stuff inside.
00:41:24
Speaker 1
There's a there's a demo program here called Fake Sensor Demo, yeah, so that's a that's just basically creates just a there's a there's a fake fake sensor header file here, so you see the I'm using a timer to create some fake sensor readings here, so the so the sensor callback obviously has a again a callback called has sample where there where there's some reading there.
00:41:53
Speaker 1
and generated by a timer, and inside here it generates a sine wave, so if you wanna if you wanna have a have a play with this here, this is here and the fake fake sensor demo, and then and then it generates something like this as JSON data here, and you can use this to play around play around with that.
00:42:16
Speaker 1
I'm going to show you something more real, so the
00:42:21
Speaker 1
because I've got it running here in my in my place here.
00:42:25
Speaker 1
I'll just show you in a minute to do it.
00:42:28
Speaker 1
So I've so I've got this I've bought a while ago this temperature sensor here that's a that's a DS 18 B20 temperature sensor which is using the so-called called called one one wire protocol.
00:42:43
Speaker 1
That's another one here I've got got in my hand.
00:42:48
Speaker 1
It's a sensor where the data only needs power and the whole transmission works via one single wire.
00:42:56
Speaker 1
It's pretty slow, but the great thing is you can connect quite a few sensors on the same wire.
00:43:06
Speaker 1
And so and measure all different kinds of stuff.
00:43:10
Speaker 1
And then I've written also on the website here.
00:43:15
Speaker 1
just something which is showing showing the temperature, and then there's also the how-to information, how to connect the sensor.
00:43:25
Speaker 1
So, I'm not I'm not going going into great detail how the sensor works.
00:43:30
Speaker 1
If you want to have a look here, you can have a look here how this driver how this driver works.
00:43:36
Speaker 1
Sadly here, because the sensor has no data ready pin to create events with a timer.
00:43:43
Speaker 1
And then this is measuring, I think, every 10 seconds, the temperature here.
00:43:51
Speaker 1
Let's just go into the server program here.
00:43:56
Speaker 1
So the server program here sampling interval 10 seconds, as I said, I'm doing this doing this as a as a timer timer event, and then and then here I've got the sensor call back here when there's new data and data has arrived.
00:44:13
Speaker 1
And in this case here, I'm just putting a sensor readings into an array, and then and then when the if I if I want to see that this data, then this array is transmitted to the web server here.
00:44:28
Speaker 1
So obviously, we don't have time to go into great detail here, but have a look at the code in your own time and see how this works.
00:44:39
Speaker 1
It's again just quite a nice
00:44:41
Speaker 1
nice reference example how this should work.
00:44:44
Speaker 1
So let's just now start this here.
00:44:49
Speaker 1
So we're sit here, fast CGI JSON API.
00:44:58
Speaker 1
So it's here.
00:45:03
Speaker 1
And let's just go to, where are we, DS 18.
00:45:16
Speaker 1
CMAC dot.
00:45:18
Speaker 1
I'm pretty sure it's already compiled, but it won't.
00:45:22
Speaker 1
No, it's no, it wasn't compiled.
00:45:25
Speaker 1
Linking executable.
00:45:27
Speaker 1
Okay, so now I've got this DSDS something server here.
00:45:36
Speaker 1
It needs as an argument the address of the sensor.
00:45:40
Speaker 1
So the sensor shows up as a text device here.
00:45:46
Speaker 1
So every sensor has a specific ID.
00:45:49
Speaker 1
In this case, that's the ID of the sensor here.
00:45:52
Speaker 1
As I said, if you're putting more than one sensor on this wire, then they will all show up automatically here as a pseudo device, which is super convenient.
00:46:02
Speaker 1
and you just need to read this pseudo file here.
00:46:07
Speaker 1
Actually, I could show you this to show you that this is really no magic.
00:46:14
Speaker 1
Yeah, so you see here, 18 means my room has 18 degrees, which is exactly what I said on my thermometer here.
00:46:25
Speaker 1
I like it.
00:46:26
Speaker 1
I like it slightly cold, and I'm not falling asleep here when I'm
00:46:30
Speaker 1
working.
00:46:31
Speaker 1
So 18 degrees is exactly what I want.
00:46:34
Speaker 1
So I'm starting the server here now.
00:46:36
Speaker 1
So now it's saying the server is up and running.
00:46:44
Speaker 1
I'll just put this here also in the chat if you want to have a look at this.
00:46:51
Speaker 1
And so the server, so my Raspberry Pi, so the web server is
00:47:00
Speaker 1
is hopefully here.
00:47:03
Speaker 1
Oh, this site can't be reached.
00:47:04
Speaker 1
That's a shame.
00:47:11
Speaker 1
Maybe HTTP.
00:47:12
Speaker 1
No, not secure.
00:47:14
Speaker 1
Okay, so here we've got the 18 degrees.
00:47:17
Speaker 1
Remember, the readings are only every 10 seconds.
00:47:23
Speaker 1
I don't have a secure connection here.
00:47:24
Speaker 1
I just have it running with HTTP, not with HTTPS.
00:47:29
Speaker 1
So anybody
00:47:30
Speaker 1
Anybody who wants to have a nosy at my room at my room temperature can have a can have a look.
00:47:37
Speaker 1
You see it's pretty constant at 18 something.
00:47:39
Speaker 1
There's not much not much variation here just now.
00:47:44
Speaker 1
Hopefully it's going up and down a bit that you see this actually actually happening that there's actually happening something here.
00:47:51
Speaker 1
So we've got got quite constant 1818.19 degrees here in this in this room just now.
00:47:59
Speaker 1
And so, the question, the question is now, so how, so that's here, that's here, here's a server.
00:48:07
Speaker 1
You see, you see there's a there's an issue here.
00:48:10
Speaker 1
I've now the now the server blocks here, and obviously I want to have this running all the time.
00:48:20
Speaker 1
So, let's just shut this down, down for a moment.
00:48:25
Speaker 1
Come on, there we go.
00:48:27
Speaker 1
So,
00:48:29
Speaker 1
There's a there's a command under Unix which is called called nohub, which means no hang up.
00:48:37
Speaker 1
So, if I'm if I'm if I'm running this program like this, then it will it will automatically also run even if I'm if I'm logging out of this terminal here, so it will just run in the background as long as the Raspberry Pi has power, yeah, so hopefully.
00:48:59
Speaker 1
This will be happening, and so, what have I have I done on the server side?
00:49:10
Speaker 1
So, if we if I if I if I go into the into ETCNGINX, there are the configuration files for the web server, and there's a subdirectory called sites enabled, and there's a file called in the default.
00:49:27
Speaker 1
And here there's a there's a configuration file for this for this web server.
00:49:34
Speaker 1
So you see here the server is called RPI band for me.
00:49:37
Speaker 1
OK.
00:49:39
Speaker 1
And then there's a there's a subdirectory here called Sensor.
00:49:43
Speaker 1
So this subdirectory here, this if I'm if I'm if I'm going into the subdirectory here that I'm reading the raw JSON data.
00:49:53
Speaker 1
So
00:49:53
Speaker 1
So, this sensor subdirectory here contains the sensor data and the C program.
00:50:02
Speaker 1
So, the fast CGI is communicating with the web server through this temporary file here, so temp sensor socket.
00:50:10
Speaker 1
So, that's a special pseudo file, a socket file, where the CGI program is communicating with.
00:50:17
Speaker 1
So, and therefore, let's just have a look here at the sensor subdirectory.
00:50:22
Speaker 1
So, if I'm
00:50:23
Speaker 1
So you see there's at least a bit of temperature rise here.
00:50:27
Speaker 1
So if I go here into sensor, you see here that now this is the JSON data which has been transmitted by the server.
00:50:44
Speaker 1
And you see here what I'm transmitting here is epoch.
00:50:46
Speaker 1
That's the time, that's the time stamp.
00:50:51
Speaker 1
That's the last value here, so the most recent one, and then here these are the temperature readings which were transmitted, and here is the time stamp of these temperature readings here, so they are also in the epoch, these time stamps here.
00:51:10
Speaker 1
Who knows what
00:51:13
Speaker 1
This number epoch here, what does it mean?
00:51:16
Speaker 1
Just to see if anybody's out there and is still listening in.
00:51:22
Speaker 1
Anybody knows how these epoch numbers work?
00:51:32
Speaker 1
So, obviously, here, if I if I'm here, it's a plot I have here proper.
00:51:43
Speaker 1
No, it's not our milliseconds.
00:51:46
Speaker 1
Epoch.
00:51:47
Speaker 1
Epoch is the number of seconds since 1970.
00:51:52
Speaker 1
So the UNIX epoch numbers are either defined as seconds or as milliseconds.
00:51:59
Speaker 1
Seconds or milliseconds since 1st of January in 1970.
00:52:08
Speaker 1
So that's the reason why these numbers are so huge.
00:52:11
Speaker 1
because they obviously quite a few seconds they have elapsed from there, and then these numbers are they have to be converted back into time stamps, so these ones here you're getting actually online online epoch epoch converters loads of them out there if you
00:52:42
Speaker 1
if you don't know what your epoch is or you need to debug it, I use it from time to time.
00:52:48
Speaker 1
Yeah, so we have now, we've got 7 minutes left in the lecture here.
00:52:53
Speaker 1
So, therefore, let's just speed on here and getting through the last bits here.
00:53:00
Speaker 1
So, the question is now, so how do we do the coding on the website?
00:53:06
Speaker 1
And, as I say, that's the only
00:53:08
Speaker 1
The only moment you're allowed to use any to use other coding languages, and I am I recommend you to do these things in JavaScript.
00:53:20
Speaker 1
And so, because that's just JavaScript is a very rich, rich language and this is easily and that's just very easy easy to write code which creates this plot here.
00:53:36
Speaker 1
So, this
00:53:38
Speaker 1
This plot here, what you've what you've just seen here, so the welcome to the room temperature stuff here, this one is done by Digraphs.
00:53:46
Speaker 1
Digraphs is a plotting library for JavaScript.
00:53:50
Speaker 1
Yeah, so this one here, which is, you know, very, very easy to use and creates beautiful plots, so you so you just don't need to do that.
00:54:02
Speaker 1
So I'm basically simply just here in the on the website.
00:54:05
Speaker 1
I'm
00:54:06
Speaker 1
loading the diagraphs here via Cloudflare, and that's us all what needs to be done.
00:54:13
Speaker 1
Then I'm also using Bootstrap here for the layout of the website here to make it look nice.
00:54:20
Speaker 1
And then you see here, then from here there's JavaScript, and then here this JavaScript here creates this beautiful plot.
00:54:33
Speaker 1
So it's pretty
00:54:35
Speaker 1
Pretty easy, so there's not much not much to do.
00:54:39
Speaker 1
So, you see down here, JavaScript is fully event and callback driven, so that's what we what we want in this lecture here.
00:54:50
Speaker 1
So, the so the primary callback in JavaScript is let's say that document is ready.
00:54:57
Speaker 1
So, when the when the website has when the web page has been has been loaded, so that one here
00:55:04
Speaker 1
When this has been, so if I'm pressing reload here, the reload button at the moment is loaded, then this callback here document ready is called, and then here document ready, I'm creating a new instance of this digraph graph here, and so I want to have time time stamp on the x-axis and temperature on the y-axis, and then
00:55:32
Speaker 1
And then, and then, in here, I'm creating a timer, so I'm updating this here every 10 seconds as a refresh, and refresh refresh is a callback function for the timer.
00:55:49
Speaker 1
So, where's refresh refresh is here, so the function refresh is defined defined here at this point here.
00:55:56
Speaker 1
So, in the refresh function, what I what I do is I'm requesting
00:56:01
Speaker 1
The data from the web server here, so, from my sensor sensor 80 here, so that's now it's a subdirectory where the data lives, so I'm creating a JSON request here to the server parse sensor.
00:56:20
Speaker 1
And then, and then, and then this JSON request has again a callback, so this function result here is again a callback which is called when data has arrived, so when the JSON data has arrived, what we had to had to look here.
00:56:35
Speaker 1
So then I just pass the JSON data here, update this here for the digraphs program, and job done.
00:56:46
Speaker 1
So, and therefore,
00:56:47
Speaker 1
It's quite a nice thing to see how JSON is, sorry, how JavaScript itself is also fully callback based.
00:56:56
Speaker 1
So in JavaScript, actually, you have really literally no main program.
00:57:01
Speaker 1
So JavaScript, everything is callback.
00:57:03
Speaker 1
So there's a callback for the whole, the window is ready, then you're creating a callback for a timer, then you're creating a callback for requests to get data from your server, and so on and so on.
00:57:16
Speaker 1
And it's the same thing if you're if you're adding adding buttons buttons to the website or so they are then you can also trigger trigger JavaScript with that.
00:57:28
Speaker 1
So you see it's pretty pretty easy easy to do with JavaScript and you know this diagraphs is absolutely amazing amazing library.
00:57:41
Speaker 1
So
00:57:42
Speaker 1
So, just as a companion to QT when or just a similarity to QT.
00:57:51
Speaker 1
So, you see it's similar to QT, so the timer is used to refresh the content, yeah?
00:57:59
Speaker 1
So, you've got the content ready on your on your C program, and then and then the refresh operation in the website requesting new data, and then this scrolls scrolls further there, yeah?
00:58:11
Speaker 1
So,
00:58:12
Speaker 1
So also the browser only is able to generate events.
00:58:16
Speaker 1
So you cannot easily have events generated in your sensor and transmit that over to the browser.
00:58:25
Speaker 1
So I would recommend not to do any kind of event, hard, hard event-based stuff, which is traveling through the browser because there's obviously no guarantee there.
00:58:36
Speaker 1
And only the browser can create events there.
00:58:40
Speaker 1
But as you know, obviously,
00:58:42
Speaker 1
Nobody knows how long a transmission lasts on the web.
00:58:47
Speaker 1
Yeah, so just a summary.
00:58:50
Speaker 1
So HTTPS is for unidirectional events created by the browser, yeah, so with buttons and screen refresh, yeah, and so you have fast CGI on the server, and I would recommend JavaScript on the client.
00:59:04
Speaker 1
Yeah, so I recommend JavaScript, and I would not recommend writing Java code and or Swift programs.
00:59:12
Speaker 1
as an app.
00:59:13
Speaker 1
I would rather write as a website in JavaScript, but it's up to you.
00:59:18
Speaker 1
So if you want to obviously torture yourself with something on the mobile phone, feel free to do this, but JavaScript is very, very powerful.
00:59:28
Speaker 1
And so I would rather look into this and you're getting also amazing libraries.
00:59:33
Speaker 1
Okay, so it's 6 P.m.
00:59:36
Speaker 1
and with that, basically the actual content is finished by that.
00:59:40
Speaker 1
Next week, I'll be only going through the assessment criteria that you basically know what you need to look out when you're working on your code.
00:59:51
Speaker 1
And so next week, Chong Feng will be there in the lab.
00:59:55
Speaker 1
I won't be there because this week I was there all day.
00:59:59
Speaker 1
And next week, Chong Feng will be there.
01:00:01
Speaker 1
They are there all week, but I will see you in the final lecture.
01:00:05
Speaker 1
Okay, so have a nice evening.