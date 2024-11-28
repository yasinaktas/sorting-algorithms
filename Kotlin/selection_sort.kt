fun selection_sort(array:MutableList<Int>, size:Int){
	for(i in 0 until size - 1){
		var min = i
		for(j in i + 1 until size){
			if(array[j] < array[min]){
				min = j
			}
		}
		val temp = array[min]
		array[min] = array[i]
		array[i] = temp
	}
}

fun main(){
	val size = 20
	val array = MutableList(size){it + 1}
	array.shuffle()
	println(array.joinToString())
	selection_sort(array,size)
	println(array.joinToString())
}
