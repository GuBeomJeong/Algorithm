func angleClock(hour int, minutes int) float64 {
    var h float64 = float64(hour) * float64(30) + float64(minutes) / float64(2);
    var m float64= 6 * float64(minutes);

    var result float64 = h-m;
    
    if result < 0{
        result = -result;
    }

    if result > 180{
        return 360 - result;
    }else{
        return result;
    }
}