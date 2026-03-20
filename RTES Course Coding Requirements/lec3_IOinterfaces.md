00:00:03
Speaker 1
So, good afternoon.
00:00:06
Speaker 1
I hope you can hear me.
00:00:08
Speaker 1
So, today, hopefully, I'm not overrunning and doing it a bit shorter.
00:00:15
Speaker 1
Okay, so what we need to talk about today, what I've only just mentioned, you know, the last time a bit in passing, was threats.
00:00:26
Speaker 1
So we already, as in the programs, we use standard thread and these things.
00:00:33
Speaker 1
And let's just look basically under the hood, what is there.
00:00:37
Speaker 1
So the idea of C is always that you have basically underneath C routines running, and then you're writing a C wrapper around it, and then just abstract it away, all the nasty stuff, what's happening in C.
00:00:51
Speaker 1
So that's just basically also what you need to do in this class.
00:00:55
Speaker 1
That's the general idea behind that.
00:00:57
Speaker 1
And so, let's just talk about threads and then and then afterwards talk about a bit some IO examples.
00:01:06
Speaker 1
So how to do the blocking IO with that.
00:01:09
Speaker 1
Okay, so where's where's my where's my presentation mode here?
00:01:14
Speaker 1
It's just covered present there.
00:01:18
Speaker 1
Okay, so let's just
00:01:20
Speaker 1
talk about threads.
00:01:21
Speaker 1
So, under if you're if you're coding under Linux, there's the underlying thread model is called is called Pthreads, and so Pthreads is a C library function, so it's a low-level C library function, and
00:01:42
Speaker 1
And the way of using this is here that you're creating a static function which has a void pointer and a void argument.
00:01:56
Speaker 1
And then you're doing the work of the thread inside here.
00:02:00
Speaker 1
So that's the idea what is underneath there, which is quite a terrible thing to do because you have basically like a void pointer.
00:02:10
Speaker 1
Here's the argument, and you're returning a void pointer from this function here.
00:02:15
Speaker 1
Void pointers are obviously a nasty stuff here.
00:02:18
Speaker 1
It does something which is typeless.
00:02:22
Speaker 1
should not be usually done.
00:02:24
Speaker 1
But in the thread model, it's using void pointers everywhere.
00:02:28
Speaker 1
And so how to create a thread in plane C?
00:02:32
Speaker 1
So this is by creating this structure here, pthreadt.
00:02:37
Speaker 1
And then you're using a function called pthreadcreate.
00:02:42
Speaker 1
And then you're basically using the thread function pointer to this function here.
00:02:50
Speaker 1
And, with that, the thread would be starting.
00:02:53
Speaker 1
So, if you want to have any kind of arguments inside there, then the argument would just be passed here also, and just be thread create, and then this would end up here as this argument from the thread function here.
00:03:08
Speaker 1
So, that's basically the way that's the way it's done low level.
00:03:13
Speaker 1
And as you see, there's no type checking, so it's quite a horrible concept.
00:03:18
Speaker 1
And the standard template libraries, the STL library, is there to make your life easier and make it safer again to run threads.
00:03:29
Speaker 1
And so that's the reason why there's a standard thread there.
00:03:34
Speaker 1
So as you see in the
00:03:36
Speaker 1
in red here, big fat warning.
00:03:38
Speaker 1
So that's the only instructive example.
00:03:41
Speaker 1
So do not do this in your project because that's already solved and it's much nicer.
00:03:47
Speaker 1
But it's always a good idea to know what's happening underneath here in these libraries because in the end there's all wrappers around horrible stuff.
00:03:58
Speaker 1
So the problem here is that so we're working with static functions.
00:04:04
Speaker 1
So, static functions cannot access instance variables.
00:04:08
Speaker 1
So, what are instance variables?
00:04:12
Speaker 1
Anybody putting this in the chat?
00:04:14
Speaker 1
So, what's the instance variable, for example?
00:04:17
Speaker 1
So, if you have a static function, we cannot access instance variables.
00:04:24
Speaker 1
What does it mean?
00:04:25
Speaker 1
You know, does anybody want to put it in the chat?
00:04:33
Speaker 1
Can anybody hear me?
00:04:35
Speaker 1
Yeah, exactly.
00:04:36
Speaker 1
As a member of a class, yeah, so, and therefore, so we cannot really access anything inside there, which is obviously a problem, so we cannot really work with classes when we're using, you know, the pthread create, so we have to somewhat like create a roundabout roundabout way, you know, actually to work with that.
00:04:54
Speaker 1
Yeah, so, the solutions I've set here, the quotation mark solution is...
00:05:00
Speaker 1
So we're using this void argument here.
00:05:02
Speaker 1
Remember, there's this void argument here and using this here basically to point to our class.
00:05:10
Speaker 1
So that's the idea behind that.
00:05:13
Speaker 1
And so using this argument here to create a pointer to our object.
00:05:21
Speaker 1
So now it's getting really messy, as you see.
00:05:23
Speaker 1
So if we have a thread class here, and so we have here
00:05:28
Speaker 1
If you see this nasty stuff, static void my thread pointer thread, and so and so here inside we have our thread, but we want to access class class variables here of this of this red class here.
00:05:43
Speaker 1
So, how do we do this here?
00:05:45
Speaker 1
So, if we so we so we're using when we're creating the thread here down here, so if you have this function start here, so we are starting this here with a pointer.
00:05:58
Speaker 1
to this thread class, my thread, which is static.
00:06:01
Speaker 1
So we can do this because it's not really part of this class.
00:06:06
Speaker 1
It just sits there, but it actually doesn't.
00:06:09
Speaker 1
And then we're using this here at the end.
00:06:12
Speaker 1
And this is then transmitted into our static function with this pthread create here.
00:06:19
Speaker 1
So that's the idea behind that.
00:06:22
Speaker 1
And then obviously that's a void pointer.
00:06:25
Speaker 1
And then we're casting it back into our class pointer here with reinterpreted cast.
00:06:32
Speaker 1
And then we can call the function, do something here, which is a standard member function.
00:06:39
Speaker 1
So you see, that's quite a messy process.
00:06:45
Speaker 1
So therefore, if you want to write some thread creation with the standard C functions,
00:06:52
Speaker 1
It is really quite an effort to do this here, so that you have to put this here, this pointer here in there, then this only becomes a void pointer, and then the void pointer needs to be reinterpreted into your class pointer.
00:07:10
Speaker 1
And then you can call something inside there, which is obviously quite a roundabout way.
00:07:17
Speaker 1
But till I would say roughly three years ago, we had to do it this way because there was no nice really workable C plus plus solution for that.
00:07:29
Speaker 1
And so what we so what we can so that's obviously messy.
00:07:35
Speaker 1
So we don't want to do this all the time because it makes your code terribly unreadable.
00:07:41
Speaker 1
So never use pthread create or this stuff in your own code.
00:07:46
Speaker 1
So that's now basically solved.
00:07:49
Speaker 1
So now in the standard template library, we have standard thread.
00:07:56
Speaker 1
Here we have a new function called standard thread, and this is basically like a wrapper around pthread to make your life easier.
00:08:06
Speaker 1
So you see now here in the start function, so if you want to start this thread here, so we just write standard thread, and then here, and my thread class do something, comma, this.
00:08:23
Speaker 1
So we have a pointer to this class here.
00:08:28
Speaker 1
And that does basically everything.
00:08:30
Speaker 1
So we can directly refer, do something here, which is not a static function.
00:08:35
Speaker 1
So remember, this is not static here.
00:08:39
Speaker 1
So we can directly write this here as a non-static function in here and directly call that without all this horrible stuff what we had to do here.
00:08:50
Speaker 1
So remember, in order to call do something here, we had to 1st
00:08:56
Speaker 1
go through this void pointer here, reinterpreting the cars, and then we only were able to do the do something.
00:09:03
Speaker 1
So now what we can do is here, we standard thread is, so we can directly refer to this instance, sorry, to this method.
00:09:16
Speaker 1
We can directly refer to this method here, and then just add to this pointer here, and then it knows it needs to call to call this here.
00:09:25
Speaker 1
so, this writing here is a bit is a bit strange, so, this and my thread class do something, what is that?
00:09:40
Speaker 1
So, in terms of syntax in C, because, if you think of this do something,
00:09:52
Speaker 1
So, we do something here has no has no bracket here, so there's no bracket behind here, so it should be already a function pointer here.
00:10:00
Speaker 1
So, remember when we when we use when we use function function pointers as it here thread function, yeah, so if you go here, so if you if you're going to our C example, so that's here without a bracket, it's a it's a function pointer, yeah, so we directly putting a function pointer in here.
00:10:21
Speaker 1
But what is that here?
00:10:23
Speaker 1
So we are writing here and my thread class do something.
00:10:29
Speaker 1
So there's no bracket behind there.
00:10:32
Speaker 1
But now we're adding this and sign here.
00:10:36
Speaker 1
So what is that in terms of syntax?
00:10:40
Speaker 1
Anybody?
00:10:41
Speaker 1
Anybody know?
00:10:42
Speaker 1
So there because that's quite a recent construct in C.
00:10:51
Speaker 1
So, you have got here, here's an and sign, my thread class do something.
00:10:56
Speaker 1
Yeah, so without the and sign, this should be already a function pointer, isn't it?
00:11:01
Speaker 1
Yeah, but it's not, and then we are writing here's and sign in front of it.
00:11:09
Speaker 1
Anybody out there?
00:11:10
Speaker 1
No?
00:11:10
Speaker 1
Okay, so there are...
00:11:13
Speaker 1
It's called, it's called functor or fuktor, however you want to pronounce this.
00:11:18
Speaker 1
So, that's a method prototype.
00:11:21
Speaker 1
So, this means I would like to access this, do something here as a prototype, but we just don't know yet in which in which object or in which class instance we would like to do this.
00:11:37
Speaker 1
And this pointer here then just merges tells them basically the standard thread is I would like to refer exactly to this do something here in this one and not in the other one.
00:11:51
Speaker 1
So that's the syntax of this and sign here.
00:11:54
Speaker 1
You will also find this in other in other contexts like the QT library for example also uses this here in its newest way of referring to methods.
00:12:06
Speaker 1
So, but the other good thing is about this here, so, if you're doing it this way, this here obviously has a type, so the type is here by thread class, and so, and therefore you cannot just call anything, you can only call something which is really inside here, so there's no void pointer nastiness happening here, so everything is type safe.
00:12:28
Speaker 1
So, also the other thing is what you see here, I've written here standard thread, use thread,
00:12:37
Speaker 1
And then I've, this is obviously created here as a variable.
00:12:41
Speaker 1
And then here I'm writing use thread equals standard thread.
00:12:47
Speaker 1
So what is happening here?
00:12:50
Speaker 1
So why didn't I use a pointer here?
00:12:54
Speaker 1
Standard thread pointer use thread.
00:12:56
Speaker 1
And then I would be writing here new standard thread.
00:13:02
Speaker 1
So you see here, so I'm assigning basically this use thread is obviously not just a variable like integer or something like this.
00:13:09
Speaker 1
It's like complex beast inside.
00:13:13
Speaker 1
And so, and then I'm creating this here.
00:13:15
Speaker 1
That's already created here as a variable.
00:13:18
Speaker 1
And then I'm overwriting it here with standard thread.
00:13:22
Speaker 1
So what is, so what is happening, happening under the hood here?
00:13:27
Speaker 1
that I don't need to use pointers.
00:13:29
Speaker 1
So why is this allowed?
00:13:32
Speaker 1
So how can I write use thread equals standard thread here?
00:13:36
Speaker 1
Obviously, for those who are victims of Python, obviously this always works, but in C, that's not non-trivial.
00:13:46
Speaker 1
So what is happening here?
00:13:48
Speaker 1
So here we are already creating an instance of use threads.
00:13:53
Speaker 1
So we are already creating an object.
00:13:55
Speaker 1
And then here we are basically here with that.
00:13:59
Speaker 1
We are creating another object and then this goes in here.
00:14:03
Speaker 1
So what is happening underneath here?
00:14:06
Speaker 1
So what kind of construction works here?
00:14:12
Speaker 1
This looks completely innocent, especially for those who are thinking in Python, but in C is actually quite a important thing to see that anybody out there
00:14:24
Speaker 1
seeing basically what is happening here at this assignment.
00:14:28
Speaker 1
So, you it's a similar thing when you're writing, for example, standard vector, and then you're assigning a vector somewhere else.
00:14:38
Speaker 1
So, what is so what is actually actually happening here?
00:14:43
Speaker 1
Nobody out there?
00:14:46
Speaker 1
Come on, there must be there must be some C nerd out there from these 50 participants who know that.
00:14:57
Speaker 1
No, use thread is not uninitialized, yeah, so it's already when you're writing standard thread use thread, it's already fully initialized, but it could not, obviously, it won't run, yeah, so it's basically something which is somewhat like dozing away or maybe it's could be seen as a thread which hasn't been started or something like that.
00:15:23
Speaker 1
Yeah, no use thread is completely initialized because this is a class, yeah, so hopefully, hopefully use thread, you know, a standard thread is a class, yeah, and hopefully everything is initialized inside.
00:15:35
Speaker 1
If it's if it's not initialized, it would be bad coding, isn't it?
00:15:39
Speaker 1
Yeah, so you so you want to initialize a class obviously throughout and anything what's inside should be all nice and happily already, you know, set to specific values.
00:15:51
Speaker 1
so, you have it, this is a class here, and everything inside use thread, this use thread contains of whatever 20 variables or something like this, and so, and they are, and then, and then there's basically here we are writing against on that thread.
00:16:08
Speaker 1
Now, this is argument here and assigning this here, so no,
00:16:18
Speaker 1
Nobody, no ideas.
00:16:19
Speaker 1
OK, so that's a that's a copy constructor.
00:16:22
Speaker 1
Yeah, so we are basically doing a copy construction here.
00:16:27
Speaker 1
Yeah, so just if you don't know what it is, I urge you to read to read about that.
00:16:35
Speaker 1
Yeah, so or just have a have a look have a look what this what this means.
00:16:42
Speaker 1
Copy constructor C I'm pretty sure you will you will find.
00:16:46
Speaker 1
allowed a lot of examples here, CPP reference, copy constructor, and I'm pretty sure there are also just beautiful examples here, how this all works here, because here, for example, B2 equals B or something like this, and it's non-trivial because A&B
00:17:10
Speaker 1
Be our classes here, and so therefore what's happening happening with all the contents which are inside there, so the so the copy constructor automatically copies everything over, and so and so every class, every every structure and every class has a default copy constructor, so it's basically everything is automatically copied over, so that's just done in a completely transparent way.
00:17:37
Speaker 1
The way this was invented was because people were obviously inspired by Python, where you can do the same thing.
00:17:44
Speaker 1
So you have one class, another class, you're just assigning that.
00:17:48
Speaker 1
And so, but this allows basically creation, so creation of classes and overwriting them or copying this stuff over without using new and delete.
00:17:59
Speaker 1
So that's the idea behind that.
00:18:01
Speaker 1
So the standard template library works mostly without any kind of
00:18:06
Speaker 1
of new and delete commands, or at least you can avoid it more or less all the time.
00:18:14
Speaker 1
Okay, so that's all about threads.
00:18:17
Speaker 1
So I don't, so I just wanted to show you what's happening underneath.
00:18:22
Speaker 1
And so obviously you should be using standard thread from the STL library.
00:18:28
Speaker 1
So what I'm talking now as the second part here is IO examples.
00:18:34
Speaker 1
So that last time I only, as I had just this push button here, where is it actually lying?
00:18:40
Speaker 1
So just on the other table, this push button there to create GPIO events.
00:18:44
Speaker 1
And so, and as you know, everything is about blocking IO.
00:18:47
Speaker 1
So what we want to do is we want to put threads to sleep and then wake them up through IO events or through blocking IO.
00:18:57
Speaker 1
And so, for the rest of this lecture today, I'm just going through a couple of examples.
00:19:05
Speaker 1
just to basically show you show you some stuff, basically how it how this is works works with different IO exam applications.
00:19:17
Speaker 1
So, some of you are doing doing audio and you are in your in your project, so just seeing this as a pitching yesterday that some of you doing doing audio stuff.
00:19:30
Speaker 1
So, the audio audio is done, so under Linux audio is called that's a low-level driver framework, and in you have you have again a blocking IO.
00:19:44
Speaker 1
So, if you want to want to record from a microphone, yeah, so some of you, know, like your what's the instrument you want to use there, you know, just and so the
00:19:56
Speaker 1
If you want to record from that and you have a microphone connected to the Raspberry Pi microphone or something like that, then you are creating this blocking blocking loop here and so this SNDPCM read I that's a blocking operation and so every time when an audio arrives it would unblock usually.
00:20:24
Speaker 1
just a number of samples, 512 or something like that, it would unblock, then you can do something in a callback with it, and then you would be going back up there and waiting, waiting for the next chunk of audio there.
00:20:40
Speaker 1
So if you need examples, so there are examples
00:20:46
Speaker 1
Examples on Moodle, pointers to applications.
00:20:51
Speaker 1
My personally, personally, where I'm usually copying and pasting stuff from is a record, so that's a simple example program.
00:21:03
Speaker 1
Oops, where's my should just go back to that.
00:21:07
Speaker 1
So, anybody who needs to do audio programming, I would recommend
00:21:14
Speaker 1
GitHub, GitHub.
00:21:21
Speaker 1
I cannot type this afternoon anymore.
00:21:26
Speaker 1
A record.
00:21:33
Speaker 1
So a record is a simple C program and it's a bit it's a bit lengthy.
00:21:40
Speaker 1
But if you are if you're if you're going going through this here, there's a somewhere it's a it's a bottom here there's a there's a PCM read function here which is no reading reading data and then and then there's further further down there's the there's a there's a main loop here capture here where the audio is read.
00:22:09
Speaker 1
And so, therefore, so I would recommend you to have a to have a look here how this how this is done with the blocking IO and then just then just copy and paste the bits and bobs you need from for your own program.
00:22:26
Speaker 1
So, that's just usually what I'm doing if I'm if I'm working working with audio.
00:22:32
Speaker 1
So, the has quite a lot of example programs.
00:22:37
Speaker 1
to do that, and I'm pretty sure that ChatGPT has also learned from that, or I hope at least, and it's not producing ********.
00:22:46
Speaker 1
So basically, be careful what is output there.
00:22:51
Speaker 1
Yeah, but so you have a microphone somewhere, then you're writing the C class in the style, and then you're creating a callback, and then you can process stuff further down the line.
00:23:02
Speaker 1
So that's us basically about audio.
00:23:07
Speaker 1
The other thing is for those, some of you might be using a mobile phone app, so you want to connect via Bluetooth.
00:23:16
Speaker 1
Bluetooth works via sockets, so via Unix sockets.
00:23:23
Speaker 1
And so you're just creating a special socket, Unix socket to your Bluetooth device.
00:23:29
Speaker 1
So I'm not going into detail, but
00:23:32
Speaker 1
but it's pretty straightforward.
00:23:34
Speaker 1
There's also example code on Moodle, and if you need more, I can also point you to more stuff, because I've written quite a lot of Bluetooth, you know, just acquisition for my for my commercial projects.
00:23:47
Speaker 1
And so, again, there's a there's a command called Rack V.
00:23:51
Speaker 1
This is blocking, so it's waiting until Bluetooth packets arrives, and then and then basically the data will be in a buffer.
00:24:00
Speaker 1
you can do something with this buffer and then just go back to sleep.
00:24:04
Speaker 1
So again, you have a callback here with a buffer from the Bluetooth received.
00:24:10
Speaker 1
So there's no need to do any low-level stuff.
00:24:13
Speaker 1
So and similar thing if you're working with Ethernet, you know, if you have a network connection via Ethernet like UDP or something like this, you also have blocking operations and you can do the same.
00:24:26
Speaker 1
So everything is already done.
00:24:28
Speaker 1
by the operating system, so we don't need to need to deal with that, which is quite nice.
00:24:34
Speaker 1
So, then let's go a bit further down to the UART.
00:24:43
Speaker 1
Yeah, so if you UART is the universal asynchronous serial port on the Raspberry Pi, so it's just a very old old old
00:24:56
Speaker 1
old school transmission does one line for the data coming coming in one line for data going out and the and again you do again a blocking a blocking read of yeah so as you see your first year as the first step you have to you have to initialize there's a UART and tell it there was a bout rate here in this case 150,000 and you know 88 bits and one one stop bit
00:25:26
Speaker 1
And you can configure all different kinds of other things with that.
00:25:30
Speaker 1
And then once it's set up, then you are having a file descriptor here.
00:25:37
Speaker 1
And then you're just doing a standard Unix read command on this.
00:25:41
Speaker 1
And then this is reading your data in.
00:25:45
Speaker 1
So in terms of UART, I have been using the UART mainly for my laser range finders.
00:25:55
Speaker 1
so they are all, that's just the most recent one here.
00:26:02
Speaker 1
I've just only written, as we see, 30th of December, brand new for a new robot here we are just building.
00:26:11
Speaker 1
So that's here, the Slam Tech RP LiDAR C1.
00:26:15
Speaker 1
So that's LiDAR here.
00:26:17
Speaker 1
just to see if it's getting this here a bit bigger, so that's a LIDAR here, and this LIDAR connects to the Raspberry Pi via UART, so it's just, you know, just a single wire for the input and a single wire for the output here.
00:26:32
Speaker 1
I've done a nice diagram here of this plug, just connecting to pin 8 and 10 here, and then that's basically everything else is done, you know, via the driver.
00:26:46
Speaker 1
That's actually for not for Raspberry Pi, but for Rock Five, but it's identical for the Raspberry Pi.
00:26:54
Speaker 1
So, the great thing is with UART is it's also blocking, yeah?
00:27:00
Speaker 1
So, as I said, so you read here, so and therefore here, if I'm if I'm going for the LiDAR stuff here, so in the LiDAR scenario, you know, the UART.
00:27:12
Speaker 1
Will wake up when there when there's new data from Lidar has arrived, and then and then it wakes up, reads reads all the data from one from one scan, and then you're getting this beautiful diagram here of our messy office.
00:27:28
Speaker 1
As you see in the corner, there's this box what we built for the robot, and then and then and then and then once the scan is over, it goes back to sleep.
00:27:38
Speaker 1
And then, and then it's waiting for the next scan of the light and wakes up again, so that's just basically how I've how it's how it's been been been written here.
00:27:48
Speaker 1
I'm using here we also some library from the manufacturer to make it easier, but in general that's just the idea, and then there's a call back inside there, and yeah, I'm doing the usual stuff here, so
00:28:04
Speaker 1
So, let's just there was also a team last year that used a one-dimensional laser laser range finder that also went in via UART.
00:28:14
Speaker 1
So UART is quite a nice thing because it has a blocking RO.
00:28:18
Speaker 1
So when data arrives, you can just wait for it and sleep in your thread until it arrives and then do something with it.
00:28:27
Speaker 1
Okay, so that's just pretty easy.
00:28:34
Speaker 1
So, where it's getting a bit more complicated is, and I'm not sure if anybody's going to use that, so there's the SPI bus.
00:28:45
Speaker 1
Yeah, so the SPI bus is for devices like ADC converters or semi-high speed boxes or something like converters, because it has quite a high high clock rate.
00:29:00
Speaker 1
The SPI bus
00:29:03
Speaker 1
If you want to want to connect devices here, so it has a serial clock, so it has a serial clock, and then it has a serial out and a serial in, and every device.
00:29:15
Speaker 1
Connected has a chip select, so if this here goes low, then this sub-device here becomes active.
00:29:22
Speaker 1
If this one here goes lower, then this goes active.
00:29:25
Speaker 1
And usually what you would be just using these CS1, CS2, CS3, you would just use standard GPIO pins for that.
00:29:33
Speaker 1
And then the, you know, the zero in and out and clock here, that is the then just managed here with the
00:29:42
Speaker 1
with the SPI bus here.
00:29:44
Speaker 1
You can also connect the chip select to special GPIO pins if you like, but I usually tend to use normal GPIO pins for that because it doesn't matter really what to do.
00:29:57
Speaker 1
I'm not sure if anybody's actually going to use SPI.
00:30:00
Speaker 1
It's not very common nowadays, but you know, if you want to use it,
00:30:08
Speaker 1
put your put your converter chip directly on the Raspberry Pi, directly plug it, plug it, plug it on there, because you know the SPI does not like long wires, so I would directly connect this as close as possible to the connector there, and so just as an advice.
00:30:37
Speaker 1
So, if you wanna if you wanna work with the SPI bus, the SPI bus has the has a curious thing that is transmitting and receiving at the same time.
00:30:47
Speaker 1
So, if the clock is running, it's direct, it's sending both data in and receiving data, which is a bit strange, so you cannot use use the standard read and write commands because then it would be it would be only going in one way.
00:31:02
Speaker 1
And so, for that, you have you have to use a special
00:31:07
Speaker 1
kernel command via the so-called IO control here.
00:31:10
Speaker 1
So you're opening your SPI device, then you're preparing this IO control command here, and then you're adding a buffer for transmission, a buffer for reception, and then the size of your area you would like to transmit, defining the speed and how much bits per word you have, and then you're sending a message out there.
00:31:34
Speaker 1
And then this will be happening at the same time.
00:31:37
Speaker 1
So reading and writing at the same time.
00:31:40
Speaker 1
So the issue is the SBI bus is non-blocking.
00:31:47
Speaker 1
So therefore, if you want to blocks only for the period of transmitting the data, but it's not able to wait for data or something like this, like the URS.
00:31:57
Speaker 1
So we need to combine this with a GPRO pin.
00:32:01
Speaker 1
So
00:32:02
Speaker 1
But I'm not sure if anybody's actually using SPI.
00:32:08
Speaker 1
But yeah, so if you want to use it, you have to use GPIO for this first data ready pin, and then use your SPI communication to transmit and receive data, and then you're doing your callback callback with that.
00:32:27
Speaker 1
A couple of years ago, we had still an SPI ADC converter, what I recommended, but now it's basically so outdated that virtually nobody's using it anymore.
00:32:37
Speaker 1
In my address, you know, as a medical data acquisition box, I'm using SPI for the ADC converter inside there.
00:32:45
Speaker 1
So if anybody wants to use that, talk to me regarding this.
00:32:50
Speaker 1
Okay, so what is a lot more popular is the I square C bus.
00:32:58
Speaker 1
So the I square C bus, the idea is that you have on the same bus.
00:33:05
Speaker 1
So these SDA and SCL lines that you have all different kinds of devices, devices on that here.
00:33:12
Speaker 1
So you can share devices.
00:33:15
Speaker 1
You have need to have somewhere pull up resistors to the supply line and then and then basically once you've got that you can connect different different devices to this bus here.
00:33:28
Speaker 1
So the SPI so the I square C bus is connected to pin three and five on the Raspberry Pi.
00:33:36
Speaker 1
So here so you see the system directly here the very first pins on the.
00:33:42
Speaker 1
on the header here, let me just see if I can show you this also on my on my on my Raspberry Pi here, so I've sold out here, this ADC converter on it, so these are these pins here, these are the SPI pins here, the first one is power supply and then there's then the two zero zero signals here, so
00:34:09
Speaker 1
And the great thing is about the SPI is it's the cable cables can be quite long, so up to half a meter or something like this.
00:34:19
Speaker 1
If you need to have longer cables, they're also level shifters and you can get you can connect devices in the region of 10 meters to it if you're using a special level level shifter chip.
00:34:34
Speaker 1
So, and therefore it's a lot more flexible than the SPI devices.
00:34:40
Speaker 1
Obviously the transmission rate is a bit slower, it's 100 kilohertz clock, whereas SPI goes up to easily one megahertz.
00:34:48
Speaker 1
So, and therefore you are, you know, just the sampling rate of your devices on it is a bit limited regarding this.
00:34:58
Speaker 1
So, if you
00:34:59
Speaker 1
If you want to, if you want to access your SPI device, you just you just open it again with a standard open command.
00:35:07
Speaker 1
You know, in this case, there's no need to use any special command.
00:35:11
Speaker 1
Let me just have a look here where our SPI devices are.
00:35:16
Speaker 1
So, if I go here on the Raspberry Pi dev,
00:35:28
Speaker 1
I square C.
00:35:30
Speaker 1
So here we see we've got here in the dev subdirectory here the I square C devices here.
00:35:36
Speaker 1
So usually it's I square I square C0 or I square C1.
00:35:42
Speaker 1
We are opening.
00:35:43
Speaker 1
So we're opening just as a read and write device here.
00:35:49
Speaker 1
And then and then and then we are able to access this bus.
00:35:53
Speaker 1
So, the I square C is designed in the way that is that is basically that every every device has a different different address on the bus here, so this controller might have the might have the address O4A634 or 99 and so and in order in order to find out what the address is.
00:36:24
Speaker 1
We can we can use this I square C detect command command for that.
00:36:29
Speaker 1
Let me just see if I've if I've actually actually installed that here.
00:36:36
Speaker 1
No, I haven't.
00:36:37
Speaker 1
Okay, let's just let's just install this here, opt install I square C tools.
00:36:45
Speaker 1
Thing is, I've oops that will that will not work with the hash sign at the back.
00:36:53
Speaker 1
just reinstalled my entire this Raspberry Pi freshly, so therefore not everything is on here.
00:37:09
Speaker 1
So, let's see I square C, where is it detects minus minus Y1?
00:37:18
Speaker 1
So, one means it's a bus, it's a bus number one.
00:37:23
Speaker 1
so here we have the I square C detect and there's a you see here there's a there's a loan forty-eight here, so there's so there's one device connected to this and what I've shown you before, so that is if I put this camera away here, so if that's this ADC converter here, that's an ADS, that's an ADS 115.
00:37:48
Speaker 1
so that one here and this is here detected as S forty-eight, so okay, I'll show you this like this, so therefore you see that's the that's the converter chip which is showing here when I'm when I'm doing the scanning.
00:38:05
Speaker 1
So, therefore, if you want to check if your I square C device is connected, then just use this I square C detect and see if this if this shows up.
00:38:19
Speaker 1
And then and then there's a special IO control command for this here, which is called I square C slave, and then this means I would like to access this device here, you know, with that.
00:38:33
Speaker 1
So then there's usually the standard convention is an I square C transmission is that then the first data byte what you're transmitting
00:38:41
Speaker 1
is the register you would like to access.
00:38:44
Speaker 1
So devices like this ADC converter, what I've connected there, like the ADS one on five, has registers.
00:38:53
Speaker 1
And then you're saying, I would like to connect to register or just read or write register O7.
00:39:01
Speaker 1
So you're writing this O7 on the I square C and then and then you would do a
00:39:08
Speaker 1
Write, write operation, for example, afterwards.
00:39:10
Speaker 1
So, you see here, write word, that means here, so I'm first sending in the first byte here, the register, and then here, in this case, I would like to write, you know, just a word consisting of two bytes.
00:39:24
Speaker 1
So, I'm putting this here into the position one and two, and then I'm writing these three bytes out there, you know, so that's the idea behind that.
00:39:34
Speaker 1
You can obviously also use more high-level commands, but I usually tend to just use a low-level commands for the RSQSE.
00:39:41
Speaker 1
There's also just Linux RSQSE library available.
00:39:45
Speaker 1
Obviously, you can use that if you like.
00:39:47
Speaker 1
It's just a kind of, it's just a package basically you can install.
00:39:53
Speaker 1
Reading is similar.
00:39:54
Speaker 1
So reading is obviously that you're first writing, writing the which register you would like to access, and then you're reading afterwards from
00:40:03
Speaker 1
from that.
00:40:04
Speaker 1
So that's the idea behind this.
00:40:07
Speaker 1
If you want to read something longer, sometimes it's also possible to read just a longer sequence of bytes.
00:40:14
Speaker 1
If the device supports this, you might be also able to read whatever, 32 bytes at the same time.
00:40:20
Speaker 1
So therefore, look at the data sheet.
00:40:22
Speaker 1
It was actually supported.
00:40:24
Speaker 1
So the SQSC is quite flexible that you're also directly able to read a whole bunch of registers at the same time.
00:40:32
Speaker 1
check out the documentation of that.
00:40:34
Speaker 1
So, okay, so obviously as a last resort, if no data ready, we have to do something else.
00:40:47
Speaker 1
Let me just, before we do that, just show you that this actually also works here.
00:40:58
Speaker 1
So, connected here to the where's my where's my cheese program here, so connected connected to the Raspberry Pi here is an ADS 1115, so if we go here to this, there we go.
00:41:24
Speaker 1
So, this is the converter chip which is connected connected here to the Raspberry Pi just in its glory.
00:41:35
Speaker 1
So, if you want to have a have a look at this at this code here and so and so the so let us connect it here you can run you can compile this program then if you have a
00:41:54
Speaker 1
this chip about.
00:41:55
Speaker 1
Let me just see here.
00:41:57
Speaker 1
There's the RPI ADS 115.
00:42:01
Speaker 1
So I've already compiled that early on and just to check if it's working.
00:42:07
Speaker 1
Also I just sold up a new ADS 115 because the other one has Chongfeng.
00:42:12
Speaker 1
So therefore I had to do it again.
00:42:15
Speaker 1
And so there's the ADS 115 printer here.
00:42:21
Speaker 1
We just, oops.
00:42:24
Speaker 1
So it's actually just a program here, no example.
00:42:37
Speaker 1
So you see here, this is the data, the data coming, the numbers coming, the raw data coming, coming from the converter.
00:42:45
Speaker 1
So if you don't believe me, that this is not actually just a fake here when I'm touching this.
00:42:50
Speaker 1
Hopefully the numbers are changing.
00:42:52
Speaker 1
So you see here this is just my noise coming coming from my body, creating changing voltage changes here at the input of the converter.
00:43:01
Speaker 1
So you see it's doing it's doing something and working.
00:43:07
Speaker 1
So have a have a rummage around here.
00:43:10
Speaker 1
So this just works exactly how I've explained this the last time.
00:43:15
Speaker 1
Yeah, so that's if you if you're if you're if you're going inside here.
00:43:21
Speaker 1
Here we have a start a start function.
00:43:24
Speaker 1
It's opens the I2C device, sets the sets the address the address of this of this converter converter chip here, then it's you know sets the sampling rate, the gain, and the channel you would like to read from, and then and then here what I haven't told you so far is the
00:43:50
Speaker 1
It's a it's a thing is that this device uses uses where's my I know hang on just that was that was the right one.
00:44:01
Speaker 1
So this so this converter chip here is not is not blocking.
00:44:08
Speaker 1
So the I square C is not is not blocking.
00:44:12
Speaker 1
So what I what I have to do is here.
00:44:15
Speaker 1
I have to use this alert pin here of this chip, and this chip alerts the thread that there's new data available.
00:44:27
Speaker 1
So this alert pin here fires at the rate what I'm what I'm specifying.
00:44:34
Speaker 1
So here in this case here, the printer here, for example, I've set this here to a sampling rate of 8 hertz.
00:44:42
Speaker 1
So, this means that this alert pin here will fire eight times per second.
00:44:48
Speaker 1
So, this alert pin here is connected connected to GPIO pin 17 on the Raspberry Pi and the GPIO pin 17 wakes up our thread.
00:45:05
Speaker 1
So, this is done done here in this in the in this program here.
00:45:10
Speaker 1
So, we're looking looking inside here you see.
00:45:14
Speaker 1
It's the same example what I've done last time with pressing the button.
00:45:19
Speaker 1
So now it's waking up the thread every time when new data has arrived here.
00:45:25
Speaker 1
So here you see I'm starting the thread RPI worker.
00:45:30
Speaker 1
And so here we have the worker and now here we have here this wait edge events and then this is waiting until this GPIO pin fires.
00:45:44
Speaker 1
And then here data is read from the ADC converter and then the thing goes back to sleep.
00:45:53
Speaker 1
So remember this, if you have a device
00:45:58
Speaker 1
which has non-blocking IO, like I square C is, you have to also use, in addition to that, a GPIO pin where data ready pin connects from the converter to the Raspberry Pi to wake up a thread.
00:46:14
Speaker 1
So if you're selecting components, make sure you have components which have something like a data ready pin.
00:46:24
Speaker 1
So remember, so we need
00:46:26
Speaker 1
this alert pin here or data ready.
00:46:28
Speaker 1
It's called alert here because it has different functions, but this is just basically set here to establish the sampling rate and to wake up threads.
00:46:39
Speaker 1
So that's the idea behind this here.
00:46:41
Speaker 1
Okay, let's just go back to the presentation.
00:46:46
Speaker 1
So obviously there are some sensors which don't have a data ready pin, and sometimes it can't be avoided.
00:46:55
Speaker 1
So, for example, the classic is the DS18B20.
00:47:01
Speaker 1
I've got actually one of them, one of them here next to me, dangling on my other Raspberry Pi, which is a temperature sensor.
00:47:10
Speaker 1
You know, very simple way of connecting it.
00:47:13
Speaker 1
It's just basically all you need is a single wire.
00:47:15
Speaker 1
So it's called a single one wire protocol.
00:47:18
Speaker 1
So there's no data ready pin.
00:47:21
Speaker 1
Actually, it takes quite a while actually to reach the temperature because this protocol is super slow.
00:47:27
Speaker 1
So you could also just run in a loop and basically try to reach the temperature as quickly as possible.
00:47:34
Speaker 1
But very often, very often, you just need to read temperature maybe only once per minute or something like that.
00:47:43
Speaker 1
And in order to do this, you probably need a timer for this.
00:47:49
Speaker 1
So, the question is, basically, so how do we how do we do a timer?
00:47:54
Speaker 1
And so, if you're really stuck with something where we need to have slow or some timing information, then again, how do we do it?
00:48:03
Speaker 1
Again, with blocking IO, yeah, so there's no there's no difference between that, yeah, so even even in our timer with the timer, we just use blocking IO because Unix provides
00:48:18
Speaker 1
fake fake read operations which are blocking for a certain period of time.
00:48:24
Speaker 1
So here you see this here.
00:48:26
Speaker 1
So first you're creating a blocking file descriptor.
00:48:29
Speaker 1
So here and you're defining basically how long something should be sleeping and how often should this be waking up.
00:48:40
Speaker 1
And then and then you're creating a creating a worker method here again in the thread.
00:48:47
Speaker 1
And there inside there's a read operation and this read operation is blocking.
00:48:53
Speaker 1
So this read operation blocks as long exactly at this period you specified before here in this value TV interval TV stuff.
00:49:04
Speaker 1
And so and then they're just starting a thread and then this then this runs at this at this at this timing here.
00:49:12
Speaker 1
So and they are for those who.
00:49:15
Speaker 1
who are, I'm always forgetting that I'm in the same browser here.
00:49:19
Speaker 1
For those who want to again play around with that, it's just, there's a, there's a, in the repository, there's something called CPP timer here.
00:49:33
Speaker 1
Why is my name gone?
00:49:43
Speaker 1
So, if you go to repositories here, CPP timer, and this just shows you how to use the blocking, the blocking, the blocking IO.
00:50:08
Speaker 1
Let's see if let's see if this how if this also works here on the Raspberry Pi.
00:50:16
Speaker 1
Hopefully it should.
00:50:18
Speaker 1
So CPP timer.
00:50:25
Speaker 1
We need to need to update the version of CMake this morning.
00:50:29
Speaker 1
That's still an old CMake version there.
00:50:41
Speaker 1
Okay, demo.
00:50:45
Speaker 1
Excellent.
00:50:45
Speaker 1
So it still works.
00:50:47
Speaker 1
So you see.
00:50:48
Speaker 1
They're just a few, a few timers, timers.
00:50:51
Speaker 1
There's actually actually two timers, no three, three timers generated, and then there's then there's basically they're just running running in parallel in different threads.
00:51:02
Speaker 1
So, you see here the first demo timer says boom, second demo timer says barn, and the third demo timer says boom.
00:51:15
Speaker 1
And that is that is all created here in this class here, and the blocking the blocking stuff is happening happening inside here in this in this in the CPP timer timer classes here, so I'm not going into detail here, so we know what I'm what I've been talking about have a have a have a look around.
00:51:43
Speaker 1
what I've done inside there.
00:51:44
Speaker 1
As I said, this is only as a last resort.
00:51:46
Speaker 1
So I don't want to see timers everywhere.
00:51:50
Speaker 1
So I want to see, you know, waking up threads from data ready pins from IO and a lot of blocking IO is there.
00:51:59
Speaker 1
So we need to also move on.
00:52:01
Speaker 1
So the last bit is lip camera.
00:52:04
Speaker 1
So are there actually some devices which I actually have already call bugs?
00:52:09
Speaker 1
And so you don't need to write your own call bugs.
00:52:12
Speaker 1
so, and there's a library called Lib Camera, and so, Raspberry Pi, they have developed their own library for camera I.O.
00:52:22
Speaker 1
that's somewhat like based on a Google project, but except of Raspberry Pi, nobody's using it, but the Raspberry Pi team is quite is quite convinced that this is a great idea, you know, so, and Lib Camera,
00:52:37
Speaker 1
It's pretty, it's pretty complex, but as I said, I'm already using callbacks, so you don't need to need to deal with this yourself, and so, therefore, if you want to want to use that, there's an example program already on my on my GitHub, and you can just quickly see here if this actually
00:53:05
Speaker 1
Was with X here, so that's a that's a repository here which is called here lip lip camera to open CV where I show you basically how this how this works and also convert you.
00:53:35
Speaker 1
the lip camera stuff from its internal raw format to OpenCV matrix.
00:53:43
Speaker 1
So, therefore, just to save you a couple of days to figure that out, because it's not it's not great, or not so easy to do that.
00:53:56
Speaker 1
What I've also done is here I've written this QT viewer here, you know, so
00:54:03
Speaker 1
Where's it?
00:54:04
Speaker 1
Where's my photo?
00:54:08
Speaker 1
We'll just get this here up, so you see that's my that's a that's a camera here, the Raspberry Pi camera connected to the to the Raspberry Pi.
00:54:22
Speaker 1
So, if I'm if I'm if I'm starting this here, hopefully with a bit of luck, this works.
00:54:34
Speaker 1
Or it doesn't, I guess, I guess here, so it's the so this is looking looking against my screen here, hopefully there's somewhere somewhere me here you see here upside down, yeah, so that's a that's a camera that's a camera sensor sensor here, so have a have a look at this at this code here in case you want to use want to use a camera that's already callback based.
00:55:02
Speaker 1
And you and you just need to need to basically put your own magic into the callback here, so and that's already established by that.
00:55:12
Speaker 1
OK, so before we're running out of time here, let's just finish finish it up here.
00:55:21
Speaker 1
OK, so I've been just talking about inputs because the inputs mainly creating, you know, events.
00:55:28
Speaker 1
But obviously, also, if you, on the other hand, if you're working with robots, then you have also outputs, but the outputs, they're usually easy because an output is usually just a setter.
00:55:41
Speaker 1
So, if you're setting something, there's no need to have it event-based, so you're just writing set left wheel speed or set right wheel speed here.
00:55:51
Speaker 1
So, that is like my robot, which is
00:55:55
Speaker 1
which is sitting here, also next to me, where is it?
00:56:02
Speaker 1
It's a bit because I'm also working working on this on this on this driving robot here.
00:56:08
Speaker 1
Yeah, so you see there's a there's a wheel on it, the Alpha board, and in order in order to turn that, we just we just use simple command, and so there's nothing dramatic about this.
00:56:21
Speaker 1
The obviously, sometimes they also have outputs, they have callbacks, like audio, for example.
00:56:27
Speaker 1
So, if you send something to an audio device, it will take a while to send it out, and then after a while there will be a callback saying, I want more data.
00:56:39
Speaker 1
So, therefore, it's not necessary that there's it's
00:56:43
Speaker 1
It's just a setter, but usually it's the case if you send something out there like a PWM device, for example, you just set the speed and job done.
00:56:53
Speaker 1
Okay, so before we're running out of time here, so a summary is that so that we have high-level IO with blocking, so we've got audio, video, Bluetooth, UART, so they're all blocking.
00:57:06
Speaker 1
We have a few low-level IO
00:57:09
Speaker 1
problems, so or if you have this connected to the Raspberry Pi, they're not blocking, so you need to have a data ready pin.
00:57:17
Speaker 1
So using dedicated one of your GPO pins and pins as data ready to wake up a thread.
00:57:22
Speaker 1
And as a last resort, so for very slow sampling rates, you can use a blocking timer file descriptor.
00:57:30
Speaker 1
But really, ideally, do everything by waking up threads from via external events.
00:57:37
Speaker 1
or via blocking IO.
00:57:42
Speaker 1
Thank you.
00:57:43
Speaker 1
Where can I find the slides?
00:57:45
Speaker 1
You can always find the slides on Moodle, like the previous ones as well, and the recording will be also there very soon.
00:57:52
Speaker 1
But I will upload the recording and the slides once I'm back from the pub, because we are leaving due, but later on it will be also online, and you can just re-watch it and read it, and so.
00:58:07
Speaker 1
So then I wish you a nice evening and I'll see you next week for the first lab.
00:58:14
Speaker 1
And then we just start with some practical work.
00:58:18
Speaker 1
Okay, good night.