<?php
main();
function insert_sort($arr) 
{
    $length = count($arr);
    for ($i = 1;$i < $length;$i++)
    {
        //确定插入比较的数
        $insertVal = $arr[$i];
        //确定与前面比较的数比较
        $insertIndex = $i - 1;
        while ($insertIndex >=0 && $insertVal < $arr[$insertIndex])
        {
            $arr[$insertIndex + 1] = $arr[$insertIndex];
            $insertIndex--;
        }
        //插入(给$insertval找到位置了)
        $arr[$insertIndex + 1] = $insertVal;
    }
    return $arr;

}

function main()
{
    $arr = [3, 2, 10, 5, 8, 6, 9, 2] ;
    $arr2 = insert_sort($arr);
    print_r($arr2); 
}
