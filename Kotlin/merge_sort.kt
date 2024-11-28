fun merge(array:MutableList<Int>, start:Int, mid:Int, end:Int){
	var i:Int
	var j:Int
	var k:Int
	val size1 = mid - start + 1
	var size2 = end - mid
	var subArray1:MutableList<Int> = mutableListOf()
	var subArray2:MutableList<Int> = mutableListOf()
	for (i in 0 until size1)
		subArray1.add(array[start + i])
	for (i in 0 until size2)
		subArray2.add(array[mid + 1 + i])
	i = 0
	j = 0
	k = start
	while (i < size1 && j < size2){
		if(subArray1[i] < subArray2[j]){
			array[k] = subArray1[i]
			i++
		}else{
			array[k] = subArray2[j]
			j++
		}
		k++
	}
	while (i < size1){
		array[k] = subArray1[i]
		i++
		k++
	}
	while (j < size2){
		array[k] = subArray2[j]
		j++
		k++
	}
}

fun merge_sort(array:MutableList<Int>, start:Int, end:Int){
	if(start < end){
		val mid:Int = (end + start) / 2
		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

fun main(){
	val size = 20
	val array = MutableList(size){it + 1}
	array.shuffle()
	println(array.joinToString())
	merge_sort(array,0,size-1)
	println(array.joinToString())
}
