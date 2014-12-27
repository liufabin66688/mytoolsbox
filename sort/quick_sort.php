<?php
main();
function quick_sort($array) 
{
    $count = count($array);
    if($count <= 1) 
    {
        return $array;
    }
    $rightArr = [];
    $leftArr = [];
    $baseKey = $array[0];
    for($i = 1 ; $i < $count ; $i ++) 
    {
        if($array[$i] <= $baseKey) 
        {
            $leftArr[] = $array[$i];
        } else {
            $rightArr[] = $array[$i];
        }
    }
    $leftArr = quick_sort($leftArr);
    $rightArr = quick_sort($rightArr);
    return array_merge($leftArr,  [$baseKey], $rightArr);
}

function main()
{
    $a = [3, 2, 10, 5, 8, 6, 9, 2] ;
    $sortA = quick_sort($a);
    echo '<pre>';
    print_r($a);
    print_r($sortA);
}
