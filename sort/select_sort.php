<?php
main();
function select_sort($arr) 
{
    $length = count($arr);
    for($i = 0; $i < $length; $i++) 
    {
        $minIndex = $i;
        for($j = $i; $j < $length; $j++) 
        {
            ($arr[$minIndex] > $arr[$j])  && $minIndex = $j;

            $tmp = $arr[$i];
            $arr[$i] = $arr[$minIndex];
            $arr[$minIndex] = $tmp;
        }
    }
    return $arr;
}

function main()
{
    $arr = [3, 2, 10, 5, 8, 6, 9, 2] ;
    $arr2 = select_sort($arr);
    print_r($arr2); 
}
