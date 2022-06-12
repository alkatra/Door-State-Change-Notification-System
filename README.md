Steps:
1.	Connect the COM and N.O. from your reed switch to your Particle device.
2.	Affix the reed switch onto your door.
3.	Connect your Particle device with the WiFi antenna and a power source.
4.	Flash the code in the previous sections onto your Particle device.
Time to test: Try opening your door. If the LED turns off, the sensor is working properly.
5.	Connect a Raspberry Pi to a buzzer and enter its terminal.
6.	Install node and npm using the following in the terminal:
sudo apt-get install -y nodejs
7.	Change the directory to a new folder and initialize NodeJS using the terminal. Then install the dependencies for our project: ExpressJS, and body parser. Then, you can create a index.js which is the entry point for our server.
npm init -y
npm i body-parse
npm i express
touch index.js
8.	Use the code provided above for Express server into the index.js.
9.	Now you can run the server using following command: node index.js.
Time to test: Open a browser, and connect to http://RASPBERRY_PI_URL:3000/ (You can find out the raspberry pi url using ifconfig -a. You should get “Hello World”. This means the server is running perfectly.
10.	Create a python file code.py and use the above code for the script connecting to the buzzer. Using a different terminal than your node server, run the python code using sudo python code.py
11.	Open a new terminal, and get a public URL (you need one for the Particle to be able to publish) using localtunnel. We will install localtunnel globally (hence -g).
npm i -g localtunnel
lt --port 3000 
12.	This will redirect the IP that it gives you to our ExpressJS server! Great, don’t close the terminal. We will keep all three terminals working 24/7.
13.	Now go to Particle console, and in the webhooks, add one to POST to our URL + /status (Fig 1) whenever we get the state publish. This will automatically send body.data (remember from our API endpoint) as the event value.
14.	If you don’t have an IFTTT account, make a free one and link your Particle device using Particle authentication.
15.	Create a flow that whenever it publishes state, you get a notification on your phone.
16.	Install the IFTTT app on your phone for notifications.
