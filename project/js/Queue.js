

 var stac = new Array();
var getArray = []
console.log(getArray)


insertQueue(getArray)

function insertQueue(item){
    for (var i = 0; i < item.length; i++) {
      inQueue(item[i])
       }

    }

function inQueue(data){


     stac.push(data)

    }

    chackDataQueue(stac)



function chackDataQueue(dataQueue){

    if (dataQueue.length <= 1) {

       outQueue()

    }else{

        timeOut()

    }

}

function outQueue(){

    while(!isEmpty()){
        console.log('out  ='+ stac.shift())

    }

}

function isEmpty(){
    return 0==stac.length
}

function timeOut(){
	// while(!isEmpty()){
  setInterval(function() { 
  	stac2 = stac.shift(); 

	console.log(stac2);
  }, 3000)
   // }
}
