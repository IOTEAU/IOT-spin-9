 var stac = [];

 function addArr(num) {
     // console.log(num)

     //  var numx = stac.indexOf(num)
     //  if (numx === -1) {
     stac.push(num)
         //  } else {
         //      stac.splice(numx, 1)
         //  }



     var upToFirebase = dbFirebase.ref("/room/108/air/air01")
     upToFirebase.set(stac.shift(0));
     setInterval(function() {
         var valToFirebase = stac.shift()
         console.log(stac)
         upToFirebase.set(valToFirebase);
         console.log(valToFirebase)
     }, 10000);
 }