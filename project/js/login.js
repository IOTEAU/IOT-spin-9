(firebase.auth().onAuthStateChanged(user => {
    if (user) {

        var x = document.querySelectorAll(".tab-from-group");
        x[1].style.display = "block";

        var x = document.querySelectorAll(".tab-from-group");
        x[0].style.display = "none";

        document.getElementById('user-data').innerHTML = user.email;

        document.getElementById('id-button').textContent = "ออกจากระบบ"


        var checkStatusText = document.querySelectorAll(".col-md-3");
        checkStatusText[0].onclick = function () { checkStatus1() };
        function checkStatus1() {
            var page1 = location.href = "page1.html"
            var checkStatusText = document.querySelectorAll(".col-md-3");
            checkStatusText[0].innerHTML = page1;

        }
        var checkStatusText = document.querySelectorAll(".col-md-3");
        checkStatusText[1].onclick = function () { checkStatus2() };
        function checkStatus2() {
            var page2 = location.href = "page2.html"
            var checkStatusText = document.querySelectorAll(".col-md-3");
            checkStatusText[1].innerHTML = page2;

        }
        var checkStatusText = document.querySelectorAll(".col-md-3");
        checkStatusText[2].onclick = function () { checkStatus3() };
        function checkStatus3() {
            var page3 = location.href = "page3.html"
            var checkStatusText = document.querySelectorAll(".col-md-3");
            checkStatusText[2].innerHTML = page3;

        }
        var checkStatusText = document.querySelectorAll(".col-md-3");
        checkStatusText[3].onclick = function () { checkStatus4() };
        function checkStatus4() {
            var page4 = location.href = "page4.html"
            var checkStatusText = document.querySelectorAll(".col-md-3");
            checkStatusText[3].innerHTML = page4;

        }



    } else {
        document.getElementById('id-button').textContent = "เข้าสู่ระบบ"
        var x = document.querySelectorAll(".tab-from-group");
        x[1].style.display = "none";

        var x = document.querySelectorAll(".tab-from-group");
        x[0].style.display = "block";

    }



}));

function check(BtnLogIn) {

    if (firebase.auth().currentUser) {
        var index = location.href = "index.html"
        document.getElementById('id-button').innerHTML = index
        firebase.auth().signOut();
        document.getElementById("myForm").reset();
        



    }

    var email = document.getElementById('txt-email').value;
    var password = document.getElementById('txt-pass').value;

    firebase.auth().signInWithEmailAndPassword(email, password)

        .catch(function (err) {
            // Handle Errors here.
            var errorCode = err.code;
            var errorMessage = err.message;

            if (errorCode == 'auth/wrong-password') {
                alert('Wrong password.');
            } else {
                alert(errorMessage);
            }
            return;
        });






};