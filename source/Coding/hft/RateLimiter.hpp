/*
采用滑动窗口方式（计数算法），在固定时间内，只需要多少个请求
实现订单网关的限流
给定 n，t两个参数
表示在t毫秒内，只处理n个order
*/

#include <deque>

class RateLimiter {
private:
	//缓冲窗口队列，接收订单的时间戳
	std::deque<uint64_t> _dq;
	int _numMsgs;
	int _timeWindow;

public:
	RateLimiter(int n, int t) : _numMsgs(n), _timeWindow(t) {

	}

	/// <summary>
	/// 判断订单是否可被处理
	/// </summary>
	/// <param name="ts">订单的时间戳</param>
	/// <returns></returns>
	bool IsRateLimiterOK(uint64_t ts) {
		if (_dq.empty()) {
			_dq.push_front(ts);
			return true;
		}

		// 最新的订单时间戳在对头，队尾的订单如果与新订单的时间戳超过了时间窗口，那么可以弹出，剩余的表示在时间窗口内已处理的订单
		while (!_dq.empty() && (ts - _dq.back() >= _timeWindow)) {
			_dq.pop_back();
		}

		// 已出来的数量小于被允许的数量，说明新订单可被处理，记录其时间戳并返回true
		if (_dq.size() < _numMsgs) {
			_dq.push_front(ts);
			return true;
		}

		return false;
	}

	int GetCountInWindow() {
		return _dq.size();
	}
};