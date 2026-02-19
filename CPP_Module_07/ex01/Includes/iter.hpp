#pragma once

template<typename ArrPtr, typename Length, typename FuncCallBack>
void	iter(ArrPtr ptr, const Length l, FuncCallBack func) {
	for (Length i = 0; i < l; i++) {
		func((*ptr)[i]);
	}
}
