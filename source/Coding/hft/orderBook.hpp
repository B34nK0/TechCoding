//订单簿由买方、卖方两个二叉树构成
struct OrderBook {
	Limit* buyTree;
	Limit* sellTree;
	Limit* lowestSell;
	Limit* highestBuy;
};

//二叉树节点记录当前价格档位以及订单数量
//节点上记录当前价位的订单队列（时间优先）
struct Limit {
	int limitPrice;
	int size;
	Limit* parent;
	Limit* leftChild;
	Limit* rightChild;
	Order* headOrder;
	Order* tailOrder;
};

//订单只需唯一标识id、交易方向、数量、价格
//采用列表方式存储订单
//
struct Order {
	int orderId;
	bool buyOrSell;
	int num;
	int limitPrice;
	Order* nextOrder;
	Order* prevOrder;
	Limit* parentLimit;
};