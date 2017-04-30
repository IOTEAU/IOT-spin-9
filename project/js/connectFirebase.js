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
    if (snap <= num0){
         var x = document.querySelectorAll(".check-status");
        x[0].innerHTML = "สถานะไม่ใช้งาน";
        x[1].innerHTML = "สถานะไม่ใช้งาน";
        x[2].innerHTML = "สถานะไม่ใช้งาน";
        x[3].innerHTML = "สถานะไม่ใช้งาน";
        x[4].innerHTML = "สถานะไม่ใช้งาน";
        x[5].innerHTML = "สถานะไม่ใช้งาน";
        x[6].innerHTML = "สถานะไม่ใช้งาน";
        x[7].innerHTML = "สถานะไม่ใช้งาน";
    }else{
         var x = document.querySelectorAll(".check-status");
        x[0].innerHTML = "กำลังใช้งาน";
        x[1].innerHTML = "กำลังใช้งาน";
        x[2].innerHTML = "กำลังใช้งาน";
        x[3].innerHTML = "กำลังใช้งาน";
        x[4].innerHTML = "กำลังใช้งาน";
        x[5].innerHTML = "กำลังใช้งาน";
        x[6].innerHTML = "กำลังใช้งาน";
        x[7].innerHTML = "กำลังใช้งาน";


    }

    document.getElementById('userinRoom').innerHTML = snapshot.val()
});