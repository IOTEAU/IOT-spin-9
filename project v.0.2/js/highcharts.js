function name() {
    var para;
    var num1 = dbFirebase.ref().child('energy'); //เปลี่ยนค่าตัวเลข มาแสดงกราฟ
    num1.on('child_added', function(snapshot) {
        para = snapshot.val();
        // console.log(para)

    });
    return para
}

$(document).ready(function() {
    Highcharts.setOptions({
        global: {
            useUTC: false
        }
    });

    var dbFirebase = firebase.database();
    var numPerple = dbFirebase.ref('UserinRoom');
    var numPerples = numPerple.on('value', function(snapshot) {
        // conssole.log("UserinRoom:" + snapshot.val());
        var snap = snapshot.val();


        Highcharts.chart('container', {
            chart: {
                type: 'spline',
                animation: Highcharts.svg, // don't animate in old IE
                marginRight: 10,
                events: {
                    load: function() {

                        // set up the updating of the chart each second
                        var series = this.series[0];
                        setInterval(function() {
                            var x = (new Date()).getTime(), // current time
                                y = name();
                            series.addPoint([x, y], true, true);
                        }, 1000);
                    }
                }
            },

            title: {
                text: 'ตารางการใช้ไฟ'
            },
            xAxis: {
                type: 'datetime',
                tickPixelInterval: 150
            },
            yAxis: {
                title: {
                    text: 'Value'
                },
                plotLines: [{
                    value: 0,
                    width: 1,
                    color: '#808080'
                }]
            },
            tooltip: {
                formatter: function() {
                    return '<b>' + this.series.name + '</b><br/>' +
                        Highcharts.dateFormat('%Y-%m-%d %H:%M:%S', this.x) + '<br/>' +
                        Highcharts.numberFormat(this.y, 2);
                }
            },
            legend: {
                enabled: false
            },
            exporting: {
                enabled: false
            },
            series: [{
                name: 'Random data',
                data: (function() {


                    // generate an array of random data
                    var data = [],
                        time = (new Date()).getTime(),
                        i;

                    for (i = -19; i <= 0; i += 1) {
                        data.push({
                            x: time + i * 1000,
                            y: name()
                        });
                    }
                    return data;
                }())
            }]
        });
    });
});



// console.log(name());