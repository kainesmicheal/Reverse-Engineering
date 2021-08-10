<receiver android:label="WriteCommandReceiver" android:name="com.adups.fota.sysoper.WriteCommandReceiver">
            <intent-filter>
                <action android:name="android.intent.action.AdupsFota.WriteCommandReceiver"/>
                <action android:name="android.intent.action.AdupsFota.OperReceiver"/>
            </intent-filter>
        </receiver>
		
we have a receiver that has two action intents, so it will be accessible for other apps

we considering thing beacuse it has the supicious name writecommandreceiver

so when an another application calls either of this service, it will invoke the onReceive funtion

`else if (action.equalsIgnoreCase("android.intent.action.AdupsFota.operReceiver")) {
            String stringExtra = intent.getStringExtra("cmd");
            String str2 = "cmd : " + stringExtra;
            if (stringExtra != null) {
                a(stringExtra.split(" "));
            }
        }`
i call a method a with input that is sent in cmd parameter

it is split with space as delimiter

`nvoke-direct {v3, p0}, Ljava/lang/ProcessBuilder;-><init>([Ljava/lang/String;)V
invoke-virtual {v3}, Ljava/lang/ProcessBuilder;->start()Ljava/lang/Process;`

processBuilder is used to create a new process and start method is called



