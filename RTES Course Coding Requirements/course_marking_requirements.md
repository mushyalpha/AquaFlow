00:01:12
Speaker 1
Okay, works.
00:02:49
Speaker 1
Do we see a person out there on Zoom?
00:02:52
Speaker 1
Can you hear me?
00:02:52
Speaker 1
I think there's one.
00:02:58
Speaker 1
Can you put something on the chat?
00:03:01
Speaker 1
In case you're there.
00:03:03
Speaker 1
My laptop is a bit slow now because it's doing Zoom and all different kinds of things at the same time.
00:03:09
Speaker 1
Yes, excellent.
00:03:10
Speaker 1
Yeah.
00:03:13
Speaker 1
Somebody can hear us out there.
00:03:16
Speaker 1
Okay, that's good to know.
00:03:23
Speaker 1
Excellent.
00:03:35
Speaker 1
Okay, so I just thought it's nicer to be in person here and not love seeing me in my office at home.
00:03:45
Speaker 1
because I don't need to present a Raspberry Pi or something like that.
00:03:48
Speaker 1
So we're just going through the assessment criteria.
00:03:52
Speaker 1
So now these are the ones which are, there's no need to take a photo of that because they are on Moodle.
00:04:00
Speaker 1
Yeah, so they are hopefully identical to that.
00:04:03
Speaker 1
There's copy and paste it over there.
00:04:05
Speaker 1
So you can go on Moodle and read them also there in your own time.
00:04:12
Speaker 1
Maybe we should just start up
00:04:14
Speaker 1
Oh, it's a Google Chrome, yeah.
00:04:20
Speaker 1
Where is the engineering model?
00:04:28
Speaker 1
But maybe I'm just drawing something on the whiteboard and you can take a photo of that.
00:04:34
Speaker 1
I think, I think there is my laptop is a bit struggling with all different tasks at the same time.
00:04:43
Speaker 1
Yeah, so here is a continuous assessment sheet marking criteria.
00:04:47
Speaker 1
So that's the one I've just spread out over the slides.
00:04:52
Speaker 1
So therefore, there's no need for you to take photos of that.
00:04:56
Speaker 1
But so I might just do some scribbles on the whiteboard there and just make it clearer.
00:05:08
Speaker 1
OK, so let us go through this here.
00:05:13
Speaker 1
you know, a structure structure of the of the of the code.
00:05:18
Speaker 1
I've been.
00:05:19
Speaker 1
I'm pretty sure.
00:05:20
Speaker 1
John Feng talked about talked about solids in his lectures.
00:05:23
Speaker 1
Yeah.
00:05:24
Speaker 1
Did you talk about solid?
00:05:26
Speaker 1
Anybody?
00:05:28
Speaker 1
Yeah.
00:05:28
Speaker 1
Okay.
00:05:28
Speaker 1
So it's so we did solid.
00:05:31
Speaker 1
So I'm just quickly going through this again, because even for me, solid is quite a very difficult concept.
00:05:37
Speaker 1
And you know, because you need to get your head around that.
00:05:40
Speaker 1
So
00:05:41
Speaker 1
So and therefore just now to make sure about the criteria here.
00:05:46
Speaker 1
Yeah, so as you see the structure of the codes, so the first criteria is solid.
00:05:51
Speaker 1
Yeah, so that we have applied all SOLID criteria, criteria are as far as you can, then this gives you an A for that.
00:06:01
Speaker 1
Yeah, so it's important to say not all SOLID criteria are easy to implement and it's a judgment
00:06:10
Speaker 1
to apply them or not.
00:06:11
Speaker 1
So therefore you have to testify that.
00:06:13
Speaker 1
So it's obviously a very good coding practice if you do it.
00:06:18
Speaker 1
But don't be religious about it, that it has to be employed.
00:06:22
Speaker 1
Yeah, that's a guiding principle regarding this.
00:06:26
Speaker 1
Yeah, so you see here, so A is really that you have thought through this, you know, just understand the right choices there.
00:06:38
Speaker 1
and applied these professionally to the problems to solve this.
00:06:44
Speaker 1
Then these are in the region that, you know, not everything is covered.
00:06:51
Speaker 1
And then as you know, D is reserved for the area where it's getting really, you know, bad.
00:06:58
Speaker 1
And so where there's serious flaws in there.
00:07:02
Speaker 1
So therefore it says serious flaws in the implementation of solid.
00:07:05
Speaker 1
and that most principles they have not applied to that.
00:07:09
Speaker 1
And then, as you know, everything beyond beyond D is a fail.
00:07:13
Speaker 1
Yeah.
00:07:13
Speaker 1
So this means we have, there's more evidence in the code, also in the documentation that you have not applied anything what's solid related.
00:07:23
Speaker 1
Yeah.
00:07:23
Speaker 1
So therefore, the
00:07:26
Speaker 1
That's the scale of that.
00:07:28
Speaker 1
And as you know, that's always the same, the same principle.
00:07:31
Speaker 1
But I'm going now through the SOLD ID, SOL ID one by one because it's quite a tricky concept and that you'll see basically how it works, you know, in this scenario.
00:07:47
Speaker 1
Yeah, so the first thing is pretty simple.
00:07:51
Speaker 1
Yeah, so single responsibility.
00:07:54
Speaker 1
Yeah, so single responsibility means.
00:07:57
Speaker 1
So if you, if you have an ADC converter.
00:08:00
Speaker 1
115, yeah.
00:08:02
Speaker 1
And so that's the one I've been using in my examples.
00:08:06
Speaker 1
So if you're listening and measures voltage.
00:08:09
Speaker 1
The class represented to that needs to really only only about about that.
00:08:16
Speaker 1
Yeah.
00:08:18
Speaker 1
So the so the class, if you write a class, it has one single responsibility.
00:08:23
Speaker 1
Yeah, so the class.
00:08:24
Speaker 1
If not, let's do your whole project.
00:08:26
Speaker 1
Yeah, so whatever what you're doing, flying car.
00:08:29
Speaker 1
Yeah, so flying car would be a bad idea.
00:08:32
Speaker 1
Yeah, that you have a class which has one single responsibility.
00:08:37
Speaker 1
Yeah.
00:08:39
Speaker 1
So therefore, if you have ADC converter, then this thing has only one job.
00:08:45
Speaker 1
Yeah, so and that is ADS 115.
00:08:49
Speaker 1
Yeah, so that's implemented there.
00:08:52
Speaker 1
Yeah, so if you have
00:08:54
Speaker 1
whatever that's the light sensor and you've got a motor and then and then these things should have single separate classes.
00:09:03
Speaker 1
Yeah.
00:09:03
Speaker 1
So and that's a single responsibility regarding this.
00:09:07
Speaker 1
Yeah.
00:09:08
Speaker 1
And so that's not important.
00:09:10
Speaker 1
Yeah.
00:09:10
Speaker 1
So so therefore, if you're writing one one big omnibus class, and then that's basically it's it's a thing.
00:09:17
Speaker 1
Yeah.
00:09:18
Speaker 1
So it's therefore
00:09:20
Speaker 1
advise up your on your classes in the way that they are with a clear responsibility.
00:09:25
Speaker 1
Yeah.
00:09:26
Speaker 1
And then please over there.
00:09:35
Speaker 1
It's very much appreciated if you don't talk.
00:09:37
Speaker 1
Yeah, we're not on Zoom.
00:09:39
Speaker 1
Yeah.
00:09:39
Speaker 1
So, so therefore, please pay attention.
00:09:43
Speaker 1
Yeah.
00:09:43
Speaker 1
If you have professions, feel free to do that, obviously.
00:09:46
Speaker 1
but don't chat about your dealer.
00:09:48
Speaker 1
Do it afterwards.
00:09:49
Speaker 1
You can do it on Zoom, but not now.
00:09:52
Speaker 1
And so the second one is the open close principle.
00:10:00
Speaker 1
So coming back to the ADC converter example.
00:10:03
Speaker 1
So open close, open close close principle means that, so we have a class lendering one channel, for example.
00:10:12
Speaker 1
And then, and then here, the second class,
00:10:15
Speaker 1
inherits from the first class, yeah?
00:10:19
Speaker 1
So that you're doing, so you're building a base class, you're saying basically, we want to measure one channel.
00:10:27
Speaker 1
And then suddenly you want to measure four channels.
00:10:32
Speaker 1
Yeah, so all of them, there you see converter has four channels.
00:10:36
Speaker 1
So then you're inheriting from the first class and then just creating a cloud.
00:10:41
Speaker 1
which is called here ADS 105, all four, three classes and then that's taking all four, we bring all four measurements.
00:10:51
Speaker 1
So that you are creating hierarchy.
00:10:54
Speaker 1
So you could also, for example, the base class could be also that's the base class called ADC converter.
00:11:02
Speaker 1
And then the inherited one would just work on this specific converter chip or something.
00:11:09
Speaker 1
So that you have a
00:11:11
Speaker 1
And so that's the open, closed principle that you are creating a base class which has based on techniques of actuality.
00:11:19
Speaker 1
And then you're adding stuff to it in the inherited version.
00:11:23
Speaker 1
Like, for example, we have what what develops in the past where the team needs to matter on 4 channels, and then you do the multiplex between these 4 channels, and you do it in this inherited class.
00:11:35
Speaker 1
Yeah.
00:11:35
Speaker 1
So that's the idea behind that.
00:11:36
Speaker 1
And so so do inheritance in this way.
00:11:40
Speaker 1
Yeah, and then maybe overloading functions or using the callback from the first function, from the first class, and then reimplementing the second one in the inherited version.
00:11:54
Speaker 1
Yeah, so let's say that's the second principle that's also pretty easy to think of.
00:12:02
Speaker 1
Yeah, so use inheritance there.
00:12:07
Speaker 1
in C++ to do this kind of stuff.
00:12:14
Speaker 1
So that one is already much more complicated, the so-called Liskov substitution principle, which is when you're going online, there are quite a few stupid examples, which are quite often not very clear what that actually mean.
00:12:32
Speaker 1
So I've
00:12:34
Speaker 1
So this is somewhat like extends the open close principle.
00:12:38
Speaker 1
Yeah, so there was a one we had then we had before.
00:12:42
Speaker 1
So we are adding functionality to this inherited class.
00:12:47
Speaker 1
But there's a problem if you're just doing it this way, because this inherited class is now specialized and can no longer be replaced by the base class.
00:13:00
Speaker 1
Yeah, so Liskov
00:13:01
Speaker 1
Substitution principle means that you still can use a base class to have all the functionality and it would not break it.
00:13:09
Speaker 1
Yeah, so this means in this case here, so the inherited version here means we have got four ABC channels basically we want to measure, yeah.
00:13:20
Speaker 1
But the four channels need to be already implemented in the base class, yeah, which was not done.
00:13:29
Speaker 1
in this one here.
00:13:30
Speaker 1
So here, in the first one, we measure only one channel and the callback will be delivering only one channel.
00:13:38
Speaker 1
And then suddenly here in this one here, obviously we need to call back with four channels.
00:13:43
Speaker 1
Yeah, so we can no longer substitute these two classes with each other, yeah, because the first one only has one channel.
00:13:54
Speaker 1
So you have no foresight and cannot do that.
00:13:58
Speaker 1
In order
00:13:59
Speaker 1
To prevent this, you really have to anticipate what the user is going to use in the future.
00:14:07
Speaker 1
Yeah, so in the base class.
00:14:09
Speaker 1
So you see here, so now I've hacked this here in the way that the base class has a scroll over here, a standard vector.
00:14:20
Speaker 1
So the standard vector can contain one reading.
00:14:24
Speaker 1
but it can also contain four readings or 60 readings.
00:14:28
Speaker 1
So it makes it flexible.
00:14:30
Speaker 1
So with that, you can still use the base class to transmit four readings.
00:14:36
Speaker 1
So even if the base classes are only transmitting one reading, but you will open up the opportunity with that.
00:14:43
Speaker 1
So there won't be any great match if you're swapping around these three two classes, you know, so the base class and the inherited one.
00:14:55
Speaker 1
So therefore, if you are creating classes, make sure that RAISE base class is flexible and is future proof.
00:15:03
Speaker 1
So that any additions would not break the interface.
00:15:08
Speaker 1
So especially in your case, because we are working with callbacks, so make your callback future proof.
00:15:17
Speaker 1
So that they are already implementing stuff which might just happen in the future.
00:15:23
Speaker 1
which have some board channels ready, then does make it call that in the way that it's also able to deliver board channels.
00:15:31
Speaker 1
If we look at my code, my code does not break the Liskov principle.
00:15:36
Speaker 1
So therefore, we have to fix them.
00:15:40
Speaker 1
So therefore, that's just the example code of the ADS 115.
00:15:45
Speaker 1
It's not future proof in this way.
00:15:49
Speaker 1
So we have to add to it.
00:15:53
Speaker 1
Make sure that you think of that.
00:15:58
Speaker 1
So the next one is the interface segregation principle.
00:16:02
Speaker 1
That's, again, pretty easy.
00:16:05
Speaker 1
Interface segregation means that does every interface.
00:16:12
Speaker 1
So in this case, obviously, our callback, oops, there's our stupid zoom thingy here in the way.
00:16:18
Speaker 1
Just get this out of the way here.
00:16:23
Speaker 1
So the, so if you, if you have, for example, two, two sensors, like a piece of sensor and a light sensor, yeah, so then you're creating two inherited classes here from, from our base, base class here and their specific functions.
00:16:43
Speaker 1
So the one is, it's a function for your sensor and the other one is a, is a function for your, for your, for your light sensor.
00:16:49
Speaker 1
So the interface, so the interface is
00:16:51
Speaker 1
is properly specified.
00:16:54
Speaker 1
So you could obviously write one big omnibus class, doing everything, and anybody who's looking at this online will be totally confused.
00:17:04
Speaker 1
So therefore, make a specific that your inherited class is doing exactly what you want.
00:17:13
Speaker 1
So like, you know, this group over there, we talked about UnoSendor,
00:17:18
Speaker 1
that you have, you know, then that's basically like a, like a, like, like one, which is derived, breaks a people center and then maybe we have also humidity center or something like this.
00:17:29
Speaker 1
And then you could add another, you know, interface for that.
00:17:33
Speaker 1
So your callbacks, make your callbacks specific and not put everything to one class because then obviously it's going to be a maintenance issue.
00:17:43
Speaker 1
So
00:17:44
Speaker 1
If then somebody modifies something with a code, then there will be side effects.
00:17:50
Speaker 1
And you will be never able to maintain that.
00:17:54
Speaker 1
So that's the idea behind that.
00:17:57
Speaker 1
So segregate this in a proper way.
00:18:00
Speaker 1
If you go online, I found an example there.
00:18:03
Speaker 1
Somebody was going on, for example, about a restaurant.
00:18:07
Speaker 1
So you go to a restaurant and the waiter knows
00:18:10
Speaker 1
And you tell the waiter, I'm vegetarian.
00:18:12
Speaker 1
And then the waiter gives you just a massive menu where the vegetarian option is somewhere at the bottom.
00:18:18
Speaker 1
And you have to search forever to find this.
00:18:20
Speaker 1
And the rest of the information is irrelevant.
00:18:23
Speaker 1
Yeah.
00:18:23
Speaker 1
So therefore, but the waiter should just give you only the menu for the vegetarians.
00:18:29
Speaker 1
Yeah.
00:18:29
Speaker 1
And then basically, it's easy and clear.
00:18:31
Speaker 1
And so therefore, so don't make a massive, massive bloat.
00:18:38
Speaker 1
And then at the end, only maybe one function is needed or something like that.
00:18:42
Speaker 1
And it creates a massive maintenance problem.
00:18:50
Speaker 1
So the last criterion, dependency inversion, is very hard to implement C++.
00:18:56
Speaker 1
And so I would not recommend necessarily to do it, only for the absolute purists who want to do this.
00:19:05
Speaker 1
So dependency inversion needs
00:19:08
Speaker 1
that when you have a driver class, so for example, like a central class and a class which is doing AI on it, then the idea is that you can switch the AI and you can switch the central class independently.
00:19:25
Speaker 1
So for example, you have different camera classes.
00:19:28
Speaker 1
So we're switching the camera class, but you cannot switch the AI.
00:19:32
Speaker 1
So you would say, okay, so I'm using just on Yodo.
00:19:35
Speaker 1
And now I want to use ZenderFlow, I want to use FyTorch or something like this.
00:19:40
Speaker 1
Sorry, not FyTorch, LibTorch, C++.
00:19:45
Speaker 1
So that you're able to replace both the low level part and the high level part.
00:19:50
Speaker 1
But the issue is your callback will most likely have a very specific information in there, which makes it hard to replace both sides.
00:20:02
Speaker 1
So if you want to do that,
00:20:05
Speaker 1
You have to use templates in C++.
00:20:09
Speaker 1
And this makes your life extremely hard.
00:20:12
Speaker 1
So I probably find a nice example on stacking about Globe, if somebody really wants to do it.
00:20:18
Speaker 1
So you see here, there's a class called lamp, and the class called button.
00:20:23
Speaker 1
So you're pressing a button and you want to trigger lamp.
00:20:25
Speaker 1
Obviously, what you want is you want to replace a button by any other button.
00:20:29
Speaker 1
and you want to replace the lamp by any other lamp, what you want to do in real life.
00:20:35
Speaker 1
So this means we have to completely decouple the lamp and the button.
00:20:41
Speaker 1
So without any kind of cross dependence.
00:20:45
Speaker 1
And as you see, so the lamp is easy.
00:20:48
Speaker 1
The lamp only has two functions, activate and deactivate.
00:20:52
Speaker 1
You have to switch it on with bio or switch it off.
00:20:55
Speaker 1
But the button, you want to
00:20:58
Speaker 1
You want to not have the button dependent on this specific lab.
00:21:03
Speaker 1
So you want to obviously use the button for any lab.
00:21:07
Speaker 1
And in order to do this, you have to introduce, there's a template here called T, which is then independent.
00:21:20
Speaker 1
And you implement something which is called switchable.
00:21:24
Speaker 1
Yeah, so the lab, yeah, but basically as a placeholder for the lab, you're creating a template called switchable.
00:21:31
Speaker 1
Yeah, so, and then with that, you can, you can keep it open, which lab is connected.
00:21:36
Speaker 1
And then only at the bottom here, you're introducing the specific lab here in this web page argument.
00:21:44
Speaker 1
So that's obviously seriously messes with your brain.
00:21:47
Speaker 1
Yeah, so, so therefore, so I would not necessarily recommend that.
00:21:51
Speaker 1
Yeah, so if you really want to do it.
00:21:54
Speaker 1
Feel free to do it.
00:21:55
Speaker 1
And so obviously you can read it.
00:21:57
Speaker 1
And everybody else can read it.
00:21:59
Speaker 1
But it might just just cause more more confusion than actually, you know, making the code.
00:22:05
Speaker 1
Yeah.
00:22:06
Speaker 1
So so the other coding languages like Java, they're they're they're making the life much easier in this in this respect.
00:22:15
Speaker 1
But C, yeah, using templates for this kind of a lot of things and templates are quite quite hard to read.
00:22:24
Speaker 1
I say no.
00:22:24
Speaker 1
So therefore, I would not necessarily recommend doing that.
00:22:28
Speaker 1
So it's your judgment there.
00:22:31
Speaker 1
So in your documentation on your GitHub or in your work, also explain what you have chosen and why you've chosen it and to make it easy for other people in the world to use your code.
00:22:47
Speaker 1
Okay, so then the next thing is in the structure of the code is encapsulation.
00:22:53
Speaker 1
Encapsulation is obviously easy in this way.
00:22:57
Speaker 1
You know, it's here in our class.
00:23:00
Speaker 1
Everything is about, it's about callbacks, consent us in the other way.
00:23:06
Speaker 1
Yeah, so encapsulation means you have loads of classes, and these classes are communicating via callbacks in terms of the event communication.
00:23:20
Speaker 1
So maybe you have a camera here in this glass.
00:23:24
Speaker 1
Then here, this camera feeds into your image classifier into a YOLO or something like this.
00:23:30
Speaker 1
YOLO will detect some inside the scene, whatever, like an apple or so that they're really kind of calling it another glass saying that's an apple.
00:23:42
Speaker 1
And then another glass will be taken to stop on the apples like the scene.
00:23:46
Speaker 1
So therefore, you have to look for the glasses.
00:23:50
Speaker 1
and it must have done all the somewhat something inside it's nicely encapsulated so so let's just as you know what I've shown you in the in my in my examples so if he if he go go to the web this laptop laptop is struggling a bit here um where's my where's my GitHub
00:24:27
Speaker 1
repositories.
00:24:32
Speaker 1
Here we go.
00:24:33
Speaker 1
So so so and therefore, as you know, I've been using this here like a like a like a example.
00:24:39
Speaker 1
how to how to do stuff.
00:24:48
Speaker 1
yeah, so we we are we are encapsulating as you know that
00:24:52
Speaker 1
The classic way of encapsulation stuff is putting everything in glass.
00:24:56
Speaker 1
And then you have the methods which the user wants to see or needs to see in the public part.
00:25:04
Speaker 1
Yeah, so the published part is the one which I exposed to the user and where the user has to interact.
00:25:14
Speaker 1
And then all the nasty stuff is happening here, of course, in the private part.
00:25:21
Speaker 1
where the user does not need to look at.
00:25:24
Speaker 1
Yeah.
00:25:24
Speaker 1
So, so I was actually captured anything, any nasty stuff here.
00:25:28
Speaker 1
If you see like a new in date, all these things which nobody really wants to see that you are, that you're putting these things in the, in the private section and all the execution, execution in the private, the private parts of that.
00:25:43
Speaker 1
And so, and so, so in terms of the assessment, it's obviously clear that
00:25:47
Speaker 1
Yeah, so A's are there if you have clearly defined what is in the interface or in the public part that you have all your data, all the variables in the private parts, then that you never access variables directly when you're via getters and setters or callbacks in that.
00:26:14
Speaker 1
So that internal data structures are efficient and provide fast, fast accessibility and computation so that you want to think of how do you store your internal data?
00:26:26
Speaker 1
Do you do double buffering or in kinds of things you want to hide away for the user?
00:26:34
Speaker 1
And then of course, when you're looking at the direction there, so the less
00:26:41
Speaker 1
And encapsulation, you have the worst.
00:26:44
Speaker 1
So one of the worst things are obviously global variables.
00:26:50
Speaker 1
So anybody who is having global variables about and storing stuff in there, something happens every year.
00:26:57
Speaker 1
Global variables obviously completely violates the encapsulation criteria.
00:27:02
Speaker 1
This will directly propel you towards a D or E region there.
00:27:08
Speaker 1
So the only
00:27:10
Speaker 1
There shouldn't be really anything in local variables in C, everything transmitted via callbacks, get us and set us.
00:27:18
Speaker 1
So then obviously, yeah, we're always getting programs where everything is just in main, just this local variables, and then these are the Fs and Gs there.
00:27:34
Speaker 1
So then in terms of failsafe memory management, yeah, so
00:27:42
Speaker 1
Use use a standard template library.
00:27:45
Speaker 1
Yeah.
00:27:45
Speaker 1
So what I've already already said, use use standard standard vector.
00:27:53
Speaker 1
So we're looking at it's a code here.
00:27:56
Speaker 1
Where's the code?
00:27:59
Speaker 1
So if you if you go here to the ADS, as you know, the ADS 115 is using also the event driven.
00:28:09
Speaker 1
stuff here via via Gpo, via this Gpo PIN.
00:28:15
Speaker 1
No, I didn't want to go there.
00:28:16
Speaker 1
I want to stay in the header file.
00:28:21
Speaker 1
I said, a file there.
00:28:27
Speaker 1
So if I if I go into the bottom here, the memory management.
00:28:32
Speaker 1
you see here.
00:28:35
Speaker 1
So they are.
00:28:36
Speaker 1
So I need to
00:28:38
Speaker 1
I need to have a pointer to the chip, and I need to have a pointer to the requests, you know, when I'm going to put in the N32 framework for the data ready pin from the ADC converter.
00:28:49
Speaker 1
So you see here I'm using standard shared pointer.
00:28:53
Speaker 1
So standard shared pointer automatically does the memory allocation business, and there's nothing to do there, so if you do that.
00:29:02
Speaker 1
But the other thing is what you should be doing is what you're seeing
00:29:07
Speaker 1
further down yet.
00:29:08
Speaker 1
So there's standard thread THR.
00:29:11
Speaker 1
Yeah, so we talked about this last time.
00:29:14
Speaker 1
So this standard thread is just create a significance variable without any kind of pointer.
00:29:22
Speaker 1
Yeah, so you could have also written standard thread new.
00:29:25
Speaker 1
And then, you know, just doing a new operation, but it's directly a significance variable.
00:29:32
Speaker 1
So we don't have any pointer here in the
00:29:37
Speaker 1
So if we go to the CPP file of here for the, when the thread is started, let's have a look here.
00:29:48
Speaker 1
Where's my start function?
00:29:50
Speaker 1
Stop.
00:29:56
Speaker 1
Data ready, search channel, where's the start function?
00:30:01
Speaker 1
There.
00:30:02
Speaker 1
So here it's a, so if you're looking here,
00:30:07
Speaker 1
at the start function.
00:30:09
Speaker 1
So here, remember what I asked, I asked a question in the zoom couple of weeks ago, there are threads equal standard thread ADS RPI work as this.
00:30:19
Speaker 1
So this looks totally innocent, but there's a lot of stuff running and going on behind the scene.
00:30:25
Speaker 1
So I'm allocating, I'm assigning threads from the standard thread here.
00:30:31
Speaker 1
So standard thread is
00:30:35
Speaker 1
It's a class, yeah?
00:30:37
Speaker 1
So therefore, it's an object, and I'm assigning THR to standard thread.
00:30:44
Speaker 1
So this is a typical copy constructor of operation.
00:30:49
Speaker 1
So therefore, there's a new object created here, and then assigned to this THR.
00:31:00
Speaker 1
And so that's a new construct which only starting in C++ and then that you can avoid pointer, pointer arithmetic with these things, yeah.
00:31:11
Speaker 1
And so that's what for anybody who does not know copy constructors, I urge you to have a look.
00:31:18
Speaker 1
So that's a way of coding.
00:31:22
Speaker 1
Some companies, they're forcing, you know, the entire code base to written only as copy constructors.
00:31:28
Speaker 1
Of course, it's a voice obviously pointers completely.
00:31:31
Speaker 1
So when looking at coding done by meta, that's why I've done quite a lot of coding for the Oculus headset.
00:31:39
Speaker 1
When looking at where, in C++ coding, it's virtually without any kind of pointer arithmetic.
00:31:44
Speaker 1
It's only done with that.
00:31:45
Speaker 1
But there's quite a lot of stuff behind the scenes going on there.
00:31:49
Speaker 1
So I'm not going into detail with that much, but so if you don't know about this, look into copy constructors.
00:31:57
Speaker 1
and the rule of 3 and rule of 5.
00:32:00
Speaker 1
It's really important there.
00:32:03
Speaker 1
So let's just go go back to this here.
00:32:08
Speaker 1
Yeah.
00:32:09
Speaker 1
So, as I said, if if you can't use copy constructors.
00:32:13
Speaker 1
use smart pointers.
00:32:15
Speaker 1
Yeah, that you start that you're allocating stuff with with some smart pointers.
00:32:22
Speaker 1
Also, if you, as you see here.
00:32:25
Speaker 1
As you see directly above there.
00:32:29
Speaker 1
So the request here.
00:32:31
Speaker 1
So I'm using standard make share instead of new.
00:32:36
Speaker 1
And then this creates basically this share for the top.
00:32:40
Speaker 1
I don't need the memory for that.
00:32:42
Speaker 1
And the great thing is, it's where we want to automatically deallocate it if it's no longer needed.
00:32:47
Speaker 1
So we don't need to do a delete command somewhere to automatically be done.
00:32:52
Speaker 1
via that.
00:32:58
Speaker 1
But ideally, try to use copy constructors as possible.
00:33:03
Speaker 1
Obviously, sometimes you have to use new delete.
00:33:06
Speaker 1
There's no way around it.
00:33:07
Speaker 1
So for example, in Qt, in Qt, Qt requires, because Qt is very old, Qt was developed in the 90s.
00:33:15
Speaker 1
And so before all these nice things came up, so in Qt, you need to
00:33:21
Speaker 1
need to use new.
00:33:23
Speaker 1
Whereas, you know, Qt usually already ties up automatically afterwards, the pointers, so we don't need to use delete there.
00:33:32
Speaker 1
So default behavior in Qt is that the delete is automatically done.
00:33:36
Speaker 1
So, yeah, so obviously never use void pointers.
00:33:42
Speaker 1
Yeah, so if we see void pointers anywhere, that does, it's just more or less a give breaker for this Ethereum here.
00:33:49
Speaker 1
Yeah, so that's obviously going towards C, C plate, C pooling.
00:33:54
Speaker 1
And that obviously also means never use malloc.
00:33:58
Speaker 1
Yeah, that's a C memory allocation function.
00:34:02
Speaker 1
That obviously generates a void pointer.
00:34:04
Speaker 1
Then you have to cast it back into the point of what we need.
00:34:08
Speaker 1
Yeah, that's just a no-no saying because obviously there's no safeguards there at all.
00:34:16
Speaker 1
So therefore, yeah, you can see
00:34:19
Speaker 1
in terms of the scale where you are there in terms of the of the memory management.
00:34:27
Speaker 1
Okay, so real time, real time coding.
00:34:32
Speaker 1
That's obviously a part of our class here, which is the most important thing.
00:34:35
Speaker 1
And this is actually the easiest, the easiest way of of of getting maps.
00:34:41
Speaker 1
Yeah.
00:34:42
Speaker 1
So so you need to assess
00:34:45
Speaker 1
how fast your system needs to react.
00:34:47
Speaker 1
So if you're saying, we are building an airbag, it needs to react within 10 milliseconds.
00:34:52
Speaker 1
You need to state to some very document and saying, or I'm doing whatever, this furry robot pet or something like this.
00:35:03
Speaker 1
And the robot pet needs to be to react to my movements within whatever, half a second or 10 million, 100 milliseconds.
00:35:10
Speaker 1
The interesting thing is in the past,
00:35:12
Speaker 1
Because I say it every year, but in the past, roughly I would say 30% of all teams do not specify anything and then earning a straight age for it, yeah?
00:35:25
Speaker 1
So if you cannot find it, yeah?
00:35:26
Speaker 1
So that's the easiest mark you can get, but roughly it's not of the teams, I just don't do it and we are absolutely bumper every year about this.
00:35:35
Speaker 1
So I'm saying it now again, it's a very easy way of doing this, yeah, put this somewhere in the documentation saying,
00:35:42
Speaker 1
So my system needs to react at this speed or so, yeah.
00:35:46
Speaker 1
But again, we always, every year, go up to act why team's doing that.
00:35:55
Speaker 1
Whereas the other thing is, it's a lot harder and goes back obviously to the core of lecture here.
00:36:02
Speaker 1
Yeah, so there actually is a real-time coding.
00:36:06
Speaker 1
As you know, the core theme,
00:36:09
Speaker 1
of this full lecture, what I started at the beginning and been going on in every Zoom lecture.
00:36:17
Speaker 1
It's about using blocking IO, you have to break up threads.
00:36:20
Speaker 1
Yeah, so you're using the blocking IO operation.
00:36:23
Speaker 1
Yeah, so as a re-operation or just waiting for an image or waiting for a key press using the GPRO library.
00:36:34
Speaker 1
Yeah, so that's a common theme.
00:36:36
Speaker 1
So this means that's a thread.
00:36:39
Speaker 1
It's mostly sleeping and only waking up if there's something coming in.
00:36:46
Speaker 1
So like a button press or a video image coming in or an audio frame arriving or something like this.
00:36:52
Speaker 1
So at a lowest level, I can see that's what I would like to see or what we would like to see.
00:37:01
Speaker 1
So this also implies what I've been going on for the start, remember the very first slide.
00:37:07
Speaker 1
Where does Kirsty standing standing where the the girl I'm using my my promos or my products that that we that we use senders which which have a data already thin.
00:37:18
Speaker 1
Yeah.
00:37:18
Speaker 1
So like the ADS 115.
00:37:21
Speaker 1
Yeah.
00:37:21
Speaker 1
So the it has data already thin, which creates an event.
00:37:26
Speaker 1
Yeah.
00:37:26
Speaker 1
So saying there's there's new data available.
00:37:29
Speaker 1
Yeah.
00:37:29
Speaker 1
So yeah.
00:37:30
Speaker 1
So our temperature senders have that and also with the
00:37:34
Speaker 1
acceleration sensors and so basically make your device selection dependent on that yeah as a as a primary thing yeah so remember something going on or about this from the very start and and it's important regarding this and so obviously fast and then as you know you know the main event loop of your of your sensor
00:38:00
Speaker 1
of your sensor system here when you're going back here to the ADS-115.
00:38:05
Speaker 1
Yeah, so here's the worker from the worker thread which is going to sleep.
00:38:10
Speaker 1
Yeah, so now this goes to sleep and the wake actually bins, then it wakes up and then triggers this callback.
00:38:19
Speaker 1
Yeah, so obviously this callback needs to be fast.
00:38:23
Speaker 1
Yeah, so if you have an ADC converter,
00:38:27
Speaker 1
which is giving you 100 readings per second, then the callback needs to finish in less than 10 milliseconds, obviously.
00:38:35
Speaker 1
I mean, you need to be sure finishes with something in 10 milliseconds.
00:38:40
Speaker 1
If it's last any longer, then you are stuffed.
00:38:43
Speaker 1
So therefore, anything what's happening in the primary callback of your Sengor needs to be fast and deterministic.
00:38:53
Speaker 1
So if there's something amazing in there,
00:38:57
Speaker 1
where it does don't know how long it lasts, then that's a bad thing.
00:39:01
Speaker 1
So we need to then just offload this.
00:39:04
Speaker 1
So therefore, so the fast deterministic code in the walk map thread should just live there.
00:39:17
Speaker 1
And then we have every team will have slow, unpredictable code.
00:39:24
Speaker 1
somewhere else, like if you're running, for example, you always image detection thing.
00:39:28
Speaker 1
So any AI normally knows how long this takes.
00:39:31
Speaker 1
Yeah.
00:39:31
Speaker 1
So it's a classification.
00:39:33
Speaker 1
Yeah.
00:39:33
Speaker 1
So you have to offload this into a regular thread.
00:39:36
Speaker 1
Yeah.
00:39:36
Speaker 1
So because you have to know how long the classifier will work.
00:39:40
Speaker 1
And then the thread at the end will have a callback and say, okay, yeah, that's my, that's a current.
00:39:46
Speaker 1
Yeah.
00:39:47
Speaker 1
So, so we have to, so the thread is
00:39:51
Speaker 1
is then triggered by, started by the, by the fast, the fast code, and then the second can do it thing independently of the fast code.
00:40:03
Speaker 1
And then what I've been also talking about, there should be no code at all, or maybe the GUI in the main program.
00:40:12
Speaker 1
So the main program should not contain any kind of code after initialization.
00:40:18
Speaker 1
So I should mention obviously there's
00:40:21
Speaker 1
insalization in there but the actual real-time execution should not have any any kind of code in there so if we go here to the to the example so the the ADS printer you know the one which was just printing numbers on the screen so here we've got here the main program insalization
00:40:50
Speaker 1
Yeah, but then at the very bottom here, the main program just sleeps.
00:40:54
Speaker 1
Yeah, so the main program just waits for, in this case, get the character to block name, and the whole main thread just falls to sleep until the user presses the button, and then the thing is finished.
00:41:07
Speaker 1
Yeah, so the other option is, of course, if you write a production code, then maybe it goes to sleep until the user presses Control C,
00:41:18
Speaker 1
or does the Qt command from the command line because that's a pure server.
00:41:25
Speaker 1
When you're thinking of this program printing my room temperature there, so there's checking until the user actually writes Qt and Qt closes off, then this will shut down.
00:41:38
Speaker 1
But there were not anything happening in there.
00:41:41
Speaker 1
So if you're writing a Qt application with a UI, it's a squeeze,
00:41:47
Speaker 1
Then we would start your team here at the last, last thing, and then our POT would put block here, and we'll just, just with GUI stuff, and then the rest would be just happening, happening in the threads started before.
00:41:59
Speaker 1
So that's what I mean to say, there's nothing happening in May.
00:42:04
Speaker 1
Obviously, we've got the initialization, but we have nothing, nothing that in the actual real-time execution happening there.
00:42:12
Speaker 1
So that's the idea behind that, whereas the,
00:42:21
Speaker 1
Yeah, so then the real-time event handling, what I told you is, you know, the preferred way of doing it is that you're using a standard function for that, yeah, so what I recommend it in using lambda functions to connect it, oops, yeah.
00:42:46
Speaker 1
Where are we?
00:42:53
Speaker 1
So obviously, the risk here that I'm getting on the touchpad here.
00:42:59
Speaker 1
So that you have got here your callback, so ADS time to float, and that you are connecting this here, here in your driver by your low level driver here via lambda band.
00:43:16
Speaker 1
As I said, you can also use the so-called ruler way of defining the callback interface with this abstract or with a purely virtual function, and then redefine that.
00:43:31
Speaker 1
But standard function in the STL library is now pretty stable.
00:43:38
Speaker 1
So last year, I didn't dare to recommend that because the STL libraries obviously still
00:43:45
Speaker 1
No, that's undergoing development.
00:43:49
Speaker 1
There was a bit more risk there.
00:43:52
Speaker 1
But that's the way.
00:43:53
Speaker 1
So don't do any of the older stuff, which you might find on the web, like bind or something like that.
00:44:01
Speaker 1
So yeah.
00:44:02
Speaker 1
So rather use standard function or use the interface approach, what I've shown you also with the FastCDI and FastDDS.
00:44:14
Speaker 1
So fast CGI and fast CGS, they're using the interface concept.
00:44:20
Speaker 1
Yeah, so using an abstract functions, abstract methods.
00:44:26
Speaker 1
Okay, oops, wrong one.
00:44:29
Speaker 1
Okay, so revision control.
00:44:33
Speaker 1
Yeah, so everybody should obviously or must use GitHub for that.
00:44:40
Speaker 1
As you know, so there's GitHub
00:44:44
Speaker 1
you are managing your project on GitHub and you are committing there.
00:44:49
Speaker 1
So good revision control means that you have proper branching, but you divide the labor into different branches of your project and then merge them from time to time.
00:45:06
Speaker 1
GitHub also shows you this beautiful graph, how this was done.
00:45:10
Speaker 1
And so when we embark it,
00:45:13
Speaker 1
I'm looking at this graph.
00:45:15
Speaker 1
Also really important are detailed commits.
00:45:18
Speaker 1
So that you commit messages, they have a explanation and refer maybe also to an issue.
00:45:27
Speaker 1
So when you work with the issue system and saying, this has resolved the issue X, that you are properly documenting that.
00:45:34
Speaker 1
So the-- I would recommend to you to
00:45:43
Speaker 1
to look at.
00:45:45
Speaker 1
Where is it here?
00:45:51
Speaker 1
Obviously, any any large large project like tensorflow or pytorch.
00:45:57
Speaker 1
So if you're going on the Github, you will find beautiful Github logs logs regarding this.
00:46:03
Speaker 1
Here, here by my, if you go to my IR filter library.
00:46:08
Speaker 1
You know.
00:46:08
Speaker 1
So you so you see here that I that I that I usually
00:46:14
Speaker 1
usually at least describe here what I have what I what I have done here.
00:46:20
Speaker 1
I have fixed the bug in the customs unit tests and so and then hopefully let's see if I if I've been been been been decent here.
00:46:30
Speaker 1
Or let's us see.
00:46:34
Speaker 1
And and so that that you have that you have descriptions which are
00:46:38
Speaker 1
which are somewhat like make very clear what was done to the code and not just writing the update.
00:46:46
Speaker 1
So also every year, some teams committing everything just via the GUI.
00:46:54
Speaker 1
So they don't do git commits, the text commands.
00:46:58
Speaker 1
When you're doing git commits, you're getting a text editor and you can describe in detail what's happening here.
00:47:04
Speaker 1
Some teams just using the GUI.
00:47:07
Speaker 1
And a GUI, then that's very often that's said, updated file, blah, blah.
00:47:12
Speaker 1
Yeah.
00:47:13
Speaker 1
And then obviously there's no information what it is.
00:47:16
Speaker 1
So when we are marking it and we're looking at your actual commit messages and we have seen 20 times files updated.
00:47:23
Speaker 1
And then it's obviously it's very hard to follow what actually done in the development.
00:47:30
Speaker 1
So if you are
00:47:32
Speaker 1
I'm sure some of you already work with companies and they know that if you're working on larger projects, the Git commit messages are very important.
00:47:42
Speaker 1
They will usually go to your boss and the boss will just, you know, just kick it off or just come back to you, tell you off that this commit was terrible.
00:47:51
Speaker 1
Yeah.
00:47:52
Speaker 1
And so therefore it's really important that they're actually describing what you've done and then it will be signed off.
00:48:00
Speaker 1
So I've contributed
00:48:01
Speaker 1
Some of you might know this to the Linux kernel kernel itself.
00:48:05
Speaker 1
So I've written code for Linux kernel to fix bucks in there.
00:48:09
Speaker 1
And Linux kernel, obviously, it's a hugely important thing in there.
00:48:13
Speaker 1
And that basically any changes need to be approved by UD five people.
00:48:20
Speaker 1
They have to all take it off before this goes into the kernel.
00:48:26
Speaker 1
And it's a big company.
00:48:27
Speaker 1
It's the same thing.
00:48:30
Speaker 1
So
00:48:30
Speaker 1
So so and therefore make it a good habit there.
00:48:36
Speaker 1
Yeah.
00:48:36
Speaker 1
So obviously the just just a fail criteria.
00:48:40
Speaker 1
It also happens every year that teams do not commit anything to to pick up and only one one day before the deadline.
00:48:49
Speaker 1
Yeah, suddenly there's one big upload you have to do to get.
00:48:54
Speaker 1
Yeah.
00:48:54
Speaker 1
So so if we if we see that, yeah, then then this
00:48:58
Speaker 1
Then it also also directly result into very low marks and just revision control.
00:49:04
Speaker 1
So also if you see that only one single person has committed, so we don't see basically that you have been working together and collaborating with us.
00:49:15
Speaker 1
So Raspberry Pi, you can SSH into it with different users and you can also work together at the same time there.
00:49:23
Speaker 1
Yeah, so project management.
00:49:27
Speaker 1
I would I would recommend I don't know what what Chong Feng recommended but I would I would recommend that that you are doing doing the project management directly directly on on on the GitHub project there I don't know if it's it's probably probably not not up up up here
00:49:52
Speaker 1
But no, GitHub offers projects.
00:49:58
Speaker 1
And so, and then that's basically, I need to, I just show you a bit later, later project when I'm going to the development part there.
00:50:10
Speaker 1
So if you, yeah, where's my, where's my presentation?
00:50:21
Speaker 1
Yeah, so, so, so do we do projects?
00:50:24
Speaker 1
Some of you already worked, worked in the industry, what I just said, and, you know, the classical way in project work is that you are, that, that you're doing sprints.
00:50:33
Speaker 1
Yeah, so that you are working for a week on a certain, on certain problems.
00:50:37
Speaker 1
And then, you know, once, once per week here, you're just describing, you know, what you've achieved.
00:50:42
Speaker 1
Some, some people are enrolling their eyes, eyes up there because they've done it, you know, so, so it's therefore the, and, but,
00:50:50
Speaker 1
define basically how you want to manage your projects.
00:50:54
Speaker 1
So you can use GitHub projects.
00:50:56
Speaker 1
Some teams in the past, let us use the issue system on GitHub, which is also useful for that.
00:51:03
Speaker 1
So we have to find issues as a work item.
00:51:07
Speaker 1
And then basically issues can be ticked off also directly with the permits.
00:51:12
Speaker 1
So in GitHub, you can, if you're putting in your permit comment or issue in there, we can directly kick it off as well.
00:51:19
Speaker 1
Yeah, so we're sort of that, you can say the issue, issue X is resolved.
00:51:23
Speaker 1
So it's quite a nice way of doing it.
00:51:29
Speaker 1
In my projects, very often is I use issues for that, because when you're working with people all over the world, yeah, that's a question at the back.
00:51:40
Speaker 1
Now we use AD Adapt to get management to tell you instead of GitHub.
00:51:45
Speaker 1
You can use any kind of, you know, just product management software, as long as we are able to see it.
00:51:53
Speaker 1
Yeah, or, you know, just the documentation is there, you know, because, you know, sometimes it's just hidden away.
00:51:59
Speaker 1
But yeah, yeah, so whatever project, if you want to use Slack or whatever, so I don't mind, yeah, so you can use anything, whatever you're used to in the past, because some of you are already
00:52:09
Speaker 1
use software, feel free to do that.
00:52:12
Speaker 1
So as long as they're able to mark it, so that there's some kind of evidence there.
00:52:19
Speaker 1
Okay.
00:52:25
Speaker 1
Okay, reliably and testing and bug and bug fixing.
00:52:28
Speaker 1
So I'm expecting from every team to do unit tests.
00:52:33
Speaker 1
Yeah, so if you are, if you have divided your classes largely up in different parts,
00:52:39
Speaker 1
then the unit test should be easy.
00:52:44
Speaker 1
And obviously, also, you must use CMake.
00:52:48
Speaker 1
It's a build system, and CMake has integrated test framework.
00:52:54
Speaker 1
If you're in CMake doing enabled testing and then you add subdirectory with tests, then you're adding tests, they are testing your different classes.
00:53:05
Speaker 1
Yeah, if you have a hardware detector classes that you're sending some fake ECG in there and detecting if the hard beef coming out there, or if you're doing a, you know, the IRR filter library here, where is it here?
00:53:18
Speaker 1
Let me see if I have the IRR library actually on here.
00:53:25
Speaker 1
There we go.
00:53:28
Speaker 1
Not compiled.
00:53:28
Speaker 1
Okay, let's just quickly compile that.
00:53:31
Speaker 1
So that's the filter library I've been maintaining for over 10 years.
00:53:38
Speaker 1
I should just maybe celebrate with a guy who was handled over to me 10 years ago.
00:53:46
Speaker 1
And maybe having a virtual beer together or so, because it's, so then here, so if I do make test, then this,
00:54:01
Speaker 1
start the test programs here and test the different filters, the Butterworth generator filters.
00:54:06
Speaker 1
So in this case, just send some random data through and see if the filter behaves.
00:54:12
Speaker 1
Yeah, and see, there could be more tests in there.
00:54:18
Speaker 1
For the sister library, for the Java library, we actually, together with the company Berlin,
00:54:28
Speaker 1
They generated all the filter responses in Python.
00:54:32
Speaker 1
And then we compared the Python response to my C++ responses.
00:54:37
Speaker 1
And we actually found one bug in it because of that.
00:54:39
Speaker 1
There was one response upside down.
00:54:42
Speaker 1
Yeah, and fixed one line of code because of that.
00:54:47
Speaker 1
Yeah, so I still need to put this thing into the C++ library in here at some point.
00:54:53
Speaker 1
But obviously, I take the bug now also in the C++ version of that.
00:54:59
Speaker 1
So it's really important to have unit tests at the end also when I'm compiling your program that I'm able to make tests.
00:55:08
Speaker 1
And then the whole thing runs and tests your classes.
00:55:13
Speaker 1
You can also use the Google testing framework, gtest, for example, if you like.
00:55:18
Speaker 1
There's also a package.
00:55:22
Speaker 1
It's up to you what you want to do.
00:55:29
Speaker 1
Documentation and PR.
00:55:32
Speaker 1
Yeah, so whatever you have on your GitHub, I need to be able to run it and compile it.
00:55:39
Speaker 1
Yeah, so you need to specify which packages are required.
00:55:45
Speaker 1
Yeah, so you know what.
00:55:47
Speaker 1
So what, so which app get installed I need to do before that.
00:55:50
Speaker 1
Yeah.
00:55:51
Speaker 1
So, and, and then also your hardware, you should, should have the bill of materials on there, installation instructions and, and also class class members should be documented.
00:56:03
Speaker 1
Yeah.
00:56:03
Speaker 1
So you should have callback functions.
00:56:06
Speaker 1
For example, here, here, explain here what the thing means.
00:56:10
Speaker 1
Yeah.
00:56:10
Speaker 1
So, as again, the Zoom, Zoom thingy covering, covering this here.
00:56:18
Speaker 1
Yeah, so that you're saying that this, like here, for example, there's this load here means it's a value in voice.
00:56:25
Speaker 1
It's just fine.
00:56:28
Speaker 1
Also.
00:56:32
Speaker 1
It's also useful to use doxygen for that.
00:56:36
Speaker 1
So it's like the, if you go into the ADS 115,
00:56:46
Speaker 1
I didn't want to do that.
00:56:48
Speaker 1
Let's go back.
00:56:54
Speaker 1
It is 115.
00:56:57
Speaker 1
So you see here, there are some.
00:56:58
Speaker 1
So in terms of documentation, so you see a prerequisites.
00:57:03
Speaker 1
I'm telling the user if they want to use this class here and it's used all over the world.
00:57:10
Speaker 1
So the user needs to do upget install cmake, obviously, and upget get install libtpoddef, because I'm using the event-driven framework there.
00:57:20
Speaker 1
And then building cmake.make.
00:57:24
Speaker 1
And then in order to install it on the computer, the user needs to do sudo make install.
00:57:31
Speaker 1
And then also what is always good is that you have example code if you're writing a low-level class.
00:57:39
Speaker 1
that this example code is somewhere there or having a test.
00:57:43
Speaker 1
And then also general usage, how to use it.
00:57:46
Speaker 1
And then in terms of documentation, if you're using Doxygen, then I usually generate a automated page here, class list you see here.
00:58:03
Speaker 1
And then Doxygen generates this beautiful
00:58:06
Speaker 1
documentation here automatically.
00:58:08
Speaker 1
So you don't need to do that by by just using the comments from the from the from the from the header parts and then restoring this into the documentation of this class here.
00:58:19
Speaker 1
Yeah.
00:58:19
Speaker 1
So and so I so I would I would recommend that you that you're using for the for the documentation the the the doxygen stuff.
00:58:34
Speaker 1
yeah.
00:58:34
Speaker 1
So
00:58:35
Speaker 1
Now, now we're coming towards the end towards the more fluffy, fluffy things like like documentation and sorry and illustration and video content.
00:58:44
Speaker 1
I had a look at last year at the team.
00:58:46
Speaker 1
There was a team called called Brew Genie, which which was an automated coffee machine.
00:58:55
Speaker 1
And so so so if you if you go into this, they created created a nice logo, and they had
00:59:04
Speaker 1
loads of photos of their setup here to entice people to build it.
00:59:10
Speaker 1
As you see, quite a lot of plumbing, plumbing involved here in this machine, what they did.
00:59:16
Speaker 1
And then there are also the 3D printed, but you see there are also bill of materials.
00:59:21
Speaker 1
So they are describing here what the user needs to buy and what it costs.
00:59:27
Speaker 1
And then they're explaining here
00:59:30
Speaker 1
how to build it all.
00:59:32
Speaker 1
Then they are also defining here which libraries are required, of course.
00:59:39
Speaker 1
Yeah, so you see here they are running unit tests also with make test.
00:59:44
Speaker 1
And then they're describing also the different classes here for different sensors, like for the motor class, and then they are the solenoid heat, they are the temperatures, and also I had a beautiful UML diagram, you know, which we always,
00:59:59
Speaker 1
appreciate.
01:00:00
Speaker 1
Yeah, if you if you do that, that you that you explain how you are, how you, how you, how your different classes work together, and the timing of this by with temporal evolution circuit diagram, how to how to connect it all up.
01:00:15
Speaker 1
And then then also here, as you see, latency, you know, evaluation and discussion here.
01:00:21
Speaker 1
And so also this this teams that were really, really, really, really good in also doing doing the Pr.
01:00:28
Speaker 1
Part here.
01:00:30
Speaker 1
So if we go back here to the last bit social media strategy, they actually had an article in RS Design Spark.
01:00:41
Speaker 1
I've got no idea how you're getting into this, but they've also written an article there with more diagrams in there, which they have made.
01:00:59
Speaker 1
And then then also that that that quite quite quite good.
01:01:02
Speaker 1
Instagram and Youtube Youtube video video clips clips out there.
01:01:09
Speaker 1
You know, showing.
01:01:16
Speaker 1
I think this is just Instagram being being difficult.
01:01:24
Speaker 1
Let's see if the yeah.
01:01:26
Speaker 1
So the you
01:01:27
Speaker 1
So YouTube here, as you see, they had a, they're posted from the very start, making here short clips.
01:01:38
Speaker 1
Yeah, as you see, pretty successful here, 7600 views on YouTube.
01:01:42
Speaker 1
It's pretty good.
01:01:44
Speaker 1
Yeah, so they worked quite hard from the start to create coverage here.
01:01:50
Speaker 1
Yeah, so therefore, so it was a pretty good project.
01:01:56
Speaker 1
Spice around all of all bio mates.
01:01:58
Speaker 1
Yeah.
01:01:58
Speaker 1
So on on this team.
01:02:00
Speaker 1
And so they are, they did a did a did a very good, very good job at the end.
01:02:05
Speaker 1
And so yeah, wrong wrong slides.
01:02:13
Speaker 1
Okay.
01:02:14
Speaker 1
So okay, finally, because it's it's already 6 as you know, there, there, there are certain deal breakers which which are give you
01:02:23
Speaker 1
which will give you no marks.
01:02:25
Speaker 1
So that's the warning.
01:02:26
Speaker 1
Yeah.
01:02:26
Speaker 1
So so so deal breaker is if you if you don't use C plus plus.
01:02:31
Speaker 1
Yeah.
01:02:31
Speaker 1
So every year some some teams ignore this this thing and then get the low marks.
01:02:37
Speaker 1
So I'm just warning you about this.
01:02:40
Speaker 1
Yeah.
01:02:40
Speaker 1
So obviously, because the real time coding, if it's a program becomes unresponsive.
01:02:47
Speaker 1
Yeah.
01:02:47
Speaker 1
So what happens every year, especially with team flowing AI.
01:02:51
Speaker 1
Yeah.
01:02:51
Speaker 1
So so there are
01:02:53
Speaker 1
you're pressing a button on the GUI saying train AI, and then the whole system freezes for two minutes until it's training.
01:03:00
Speaker 1
So that's obviously not a bad idea.
01:03:02
Speaker 1
So any, and obviously using wait and sleep statements to establish timing, because it's a multi-chance operating system in Linux, and wait and sleep is not reliable.
01:03:14
Speaker 1
So because there are different tasks running at the same time, so certainly that we're kind of reliable.
01:03:19
Speaker 1
So as I said, use waiting up threads,
01:03:23
Speaker 1
It's a primary thing.
01:03:25
Speaker 1
And use that as a main way of doing your time.
01:03:31
Speaker 1
Not using callbacks, yeah.
01:03:33
Speaker 1
So what happens every year, one single massive loop, yeah, Arduino style, yeah, where, you know, waiting for this thing, doing a bit of this, waiting for this thing, and obviously our stuff higher up, it becomes unresponsive, the more tasks are changed.
01:03:51
Speaker 1
along the lines.
01:03:52
Speaker 1
Yeah.
01:03:53
Speaker 1
So so therefore, all this hobby this stuff you find on online about Arduino, what is as a as a play.
01:03:59
Speaker 1
Yeah.
01:03:59
Speaker 1
So so never, never use anything like that.
01:04:03
Speaker 1
Yeah.
01:04:03
Speaker 1
So no indication of work control.
01:04:06
Speaker 1
What already said.
01:04:07
Speaker 1
If you, if you see teams uploading their stuff at the last minute, this, this, this will automatically resolve.
01:04:15
Speaker 1
very, very low marks.
01:04:16
Speaker 1
And so that's obviously a no-no because we have all of our teamwork here.
01:04:20
Speaker 1
We're working together on our topic.
01:04:23
Speaker 1
And then the final thing is trivial work.
01:04:26
Speaker 1
So if you're just doing PR and that's producing loads of fluff, but not much code, which also happened in the past.
01:04:37
Speaker 1
I mentioned this with a team.
01:04:39
Speaker 1
There was a team a couple of years ago that just connected to potential meter to the Raspberry Pi.
01:04:44
Speaker 1
and printed the readings from the screen and and called this robot angle angle encoder.
01:04:48
Speaker 1
Yeah.
01:04:49
Speaker 1
And and that was basically done within 5 min, I think.
01:04:54
Speaker 1
Yeah.
01:04:54
Speaker 1
And so so therefore, obviously, that that was not not generating any marks for that.
01:05:00
Speaker 1
Okay.
01:05:00
Speaker 1
But apart apart from that, so I so I hope I see you all in the in the lab next week.
01:05:06
Speaker 1
So I'll be back back next week again.
01:05:10
Speaker 1
And I wish you wish you a nice evening.
01:05:14
Speaker 1
If I.