fun findPivotIndex(array:MutableList<Int>, start:Int, end:Int):Int{
	var pivotIndex = start
	var i = start + 1
	var j = end
	while(i <= j){
		if(array[pivotIndex] > array[i]) i++
		else if(array[pivotIndex] <= array[j]) j--
		else{
			var temp = array[i]
			array[i] = array[j]
			array[j] = temp
			i++
			j--
		}
	}
	var temp = array[pivotIndex]
	array[pivotIndex] = array[j]
	array[j] = temp
	return j
}

fun quickSort(array:MutableList<Int>, start:Int, end:Int){
	if(start < end){
		val pivotIndex = findPivotIndex(array, start, end)
		quickSort(array, start, pivotIndex - 1)
		quickSort(array, pivotIndex + 1, end)
	}
}

fun main(){
	val size = 20
	val array = MutableList(size){it + 1}
	array.shuffle()
	println(array.joinToString())
	quickSort(array,0,size-1)
	println(array.joinToString())
}



