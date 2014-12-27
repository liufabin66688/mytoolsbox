<?php
main();
function bubble_sort($array)
{
    $count = count($array);
    if($count <= 1) 
    {
        return $array;
    }
    for($i =0; $i< $count; $i++)
    {
        for($j = 1 ; $j < $count -$i ; $j ++) 
        {
            if($array[$j] < $array[$j - 1]) 
            {
                $temp = $array[$j];
                $array[$j] = $array[$j - 1];
                $array[$j - 1] = $temp;
            }
        }
    }
    return $array;
}

function main()
{
    $a = [3,2,10,5,8,6,9,2] ;
    $sortA = bubble_sort($a);
    echo '<pre>';
    print_r($a);
    print_r($sortA);
}
