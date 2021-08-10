tasks:
	
-> find if the app makes any sms
-> find if the application asks for consent before making the sms


we can start of with a string search for sms

sendTextMessage is the api call that is inbuilt in android to send an sms

sendMessage function camera.loading class call sendTextMessage()

<activity android:label="@string/app_name" android:name="com.cp.camera.Loading" android:screenOrientation="portrait">
            <intent-filter>
                <action android:name="android.intent.action.MAIN"/>
                <category android:name="android.intent.category.LAUNCHER"/>
            </intent-filter>
        </activity>
		
as per the manifest file the camera.loading class is called as soon as the application is opened.

thus onCreate method will be called in that class


String operator = ((TelephonyManager) getSystemService("phone")).getSimOperator();

get the current sim operator name

loginByPost(operator) -> loginByPost method is called with operator

it return a number for the operator
JSONObject object = new JSONObject(loginByPost(operator));
this.service = object.getString("service");

service is stored seperatable in a variable

ActivityCompat.requestPermissions(Loading.this, new String[]{"android.permission.SEND_SMS"}, 1);

when any permission is requested

onRequestPermissionsResult is called in the serivice class

else if (this.service != null && this.content != null) {
            sendMessage(this.service, this.content);
			
sms.sendTextMessage(mobile, null, msg, sentintent, null); 
wil be called inside sendmessage funciton

if the user consents that the application can access sms, the sms will be sent


this is not good, because it doesnt ask if it can send a particular sms, it just request permissions to access sms, not send one



