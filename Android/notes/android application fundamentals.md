Android applications are in the apk file format. 
APK is basically a zip file

apk contents

AndroidManifest.xml
META-INF/ -> contains all certificates
classes.dex -> dalvik byte code for application in dex file format
lib/ -> native libraries for the application
assets/ -> any other files needed by the application, additional lib files

Instead of the java code being run in the java virtual machine (JVM) like in desktop applications

in Android java code is compiled to Dalvik Executable (DEX) bytecode format.

Android Runtime (ART) is used for compiling java code to dex

to reverse tha t process we can get java code from dex byte code

Dex Bytecode -> smali -> decompiled java (or kolin) code

smail is like the assemlbly language between the java code and byte code

	public static void helloworld() {
		System.out.println("Hello World");
	}

	.method public static helloworld()v
		.register 2
		sget-object v0, Ljava/lang/System;->out:Ljava/io/PrintStream;
		const-string v1, "Hello World"
		invoke-virtual {v0,v1}, Ljava/io/PrintStream;->println(Ljava/lang/String)V
		return-void
	.end method


the launcher activity is the activity that is started when a user clicks on the icon for an application.

it will be provided in the androidmanifest file.

Services:

Intents are used to start a service in the background

when the startService API is called to start a Service, the onStart method in the Service is executed.

BroadCast Receivers:

broadcasts can be thought of a messaging system and broadcast receivers are the listeners.

if an application has registered a receiver for a specific broadcast, the code in that receiver is executed when the system sends the broadcase

there are two ways an app can register a receiver, in the app's manifest or dynamicall registerd in the app code using registerReceiver() api call

in both cases to register the receiver, the intent fileters for the receiver are set.
these intent filters are the broadcasts that should trigger the receiver.

onReceive in the broadcastReciever class is executed when the registered receiver receives a broadcast.

Exported Components (Services & Activities):

Services and Activities can alse be exported, which allows other processes on the device to start the service or launch the activity

by default it will be set to false, unles the element is set to true in the manifest or intent filters aredefined for the activity or service.

<service android:name=".exportedservice" android:exported="true" />
<activity android:name=".exportedactivity" android:exported="true" />

even if the service was set if false, and if has any intent defined that automatically it is exported for other apps to intract with that

<receiver android:name="com.adups.fota.sysoper.TaskReceiver">
            <intent-filter>
                <action android:name="android.net.conn.CONNECTIVITY_CHANGE"/>
                <action android:name="android.intent.action.ACTION_POWER_CONNECTED"/>
            </intent-filter>
	
	here the reciver export defauls to false, bu the intents definded can be access by other applications throught the action or activity defined
	

Application Subclass:

Android applications can define a subclass of Application.
Applications can, but do not have to define a custom subclass of application.
if a app defines a application subclass, this class is instantiated prior to any other class in the applcation.

if the attachBaseContext method is defined in the application subclass, it is called first, before the onCreate method.

use jadx-gui for decompiling


