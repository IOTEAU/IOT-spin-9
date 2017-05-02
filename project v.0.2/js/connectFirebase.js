// Initialize Firebase

var config = {
    apiKey: "AIzaSyB2_l8HIycLAdM6a9vA9XMaS_VPqxmBK1o",
    authDomain: "datacontro.firebaseapp.com",
    databaseURL: "https://datacontro.firebaseio.com",
    projectId: "datacontro",
    storageBucket: "datacontro.appspot.com",
    messagingSenderId: "585589132177"
};
firebase.initializeApp(config);



var dbFirebase = firebase.database();
var numPerple = dbFirebase.ref('UserinRoom');
var numPerples = numPerple.on('value', function(snapshot) {



    
    
    // console.log("Airtwo:" + snapshot.val());
    var snap = snapshot.val();
   


    var num0 = 0;

  var LED 
  var AIR
    if (snap <= num0) {

        LED = document.querySelectorAll("#button");
        //S LED //
        LED[0].style.display = "block";
       
        
         AIR = document.querySelectorAll("#button1");
        //S AIR //
        AIR[0].style.display = "none";
       
    } else {
         LED = document.querySelectorAll("#button");
        //S101 LED //testSensor
        LED[0].style.display = "none";
        
        
        
        

         AIR = document.querySelectorAll("#button1");
        //S101 LED //
        AIR[0].style.display = "block";
        
        
    }

    document.getElementById('userinRoomS101').innerHTML = snapshot.val()
    


});

var numPerple1 = dbFirebase.ref('air');
var numPerples = numPerple1.on('value', function(snapshot) {
 var snap1 = snapshot.val();


var num1 =0
  var AIRS101
    if (snap1 <= num1) {

        
        AIRS101 = document.querySelectorAll("#button");
       
        AIRS101[1].style.display = "block";
        
         AIRS101 = document.querySelectorAll("#button1");
        //S AIRS101 //
        AIRS101[1].style.display = "none";
     



    } else {
         AIRS101 = document.querySelectorAll("#button");
        //S101 AIRS101 //testSensor
        AIRS101[1].style.display = "none";
        
        
        
        

         AIRS101 = document.querySelectorAll("#button1");
        //S101 LED //
        AIRS101[1].style.display = "block";
        
        
       
       

    }
});

//random เข้า Firebase
// var num = dbFirebase.ref('num');
// setInterval(function() {
//     num.push(Math.random() * 100)
// }, 1000)