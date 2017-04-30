// Initialize Firebase



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
    console.log("Airtwo:" + snapshot.val());
    var snap = snapshot.val();
    var num0 = 0;
    if (snap <= num0) {
        var x = document.querySelectorAll("#button");
        //S LED //
        x[0, 1, 2, 3, 4, 5, 6, 7].style.display = "block";
        var x = document.querySelectorAll("#button1");
        //S AIR //
        x[0, 1, 2, 3, 4, 5, 6, 7].style.display = "none";



    } else {
        var x = document.querySelectorAll("#button");
        //S101 LED //testSensor
        x[0].style.display = "none";
        //S101 AIR //
        x[1].style.display = "none";
        //S102 LED //
        x[2].style.display = "none";
        //S102 AIR //
        x[3].style.display = "none";
        //S103 LED //
        x[4].style.display = "none";
        //S103 AIR //
        x[5].style.display = "none";
        //S104 LED //
        x[6].style.display = "none";
        //S104 AIR //
        x[7].style.display = "none";

        var x = document.querySelectorAll("#button1");
        //S101 LED //
        x[0].style.display = "block";
        //S101 AIR //
        x[1].style.display = "block";
        //S102 LED //
        x[2].style.display = "block";
        //S102 AIR //
        x[3].style.display = "block";
        //S103 LED //
        x[4].style.display = "block";
        //S103 AIR //
        x[5].style.display = "block";
        //S104 LED //
        x[6].style.display = "block";
        //S104 AIR //
        x[7].style.display = "block";


    }

    document.getElementById('userinRoom').innerHTML = snapshot.val()
});

//random เข้า Firebase
var num = dbFirebase.ref('num');
setInterval(function() {
    num.push(Math.random() * 100)
}, 1000)