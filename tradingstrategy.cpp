#include "tradingstrategy.h"


/**
 * @brief Constructor for our abstract trading strategy class.
 * @author Hamid Zargar
 * @param ticker Represents the ticker that the trading strategy will execute on
 * @param strategy_id Represents the strategy id assigned to the trading strategy
 */

TradingStrategy::TradingStrategy(std::string ticker, int strategy_id){

    this->ticker= ticker;
    this->strategy_id = strategy_id;
};

/**
 * @brief Adds a trade to the local history.
 * @author Hamid Zargar
 * @param trade Represents the trade we will be adding to our local strategy history
 */

void TradingStrategy::addToLocalHistory(const Trade& trade){
    this->local_history.push_back (trade);
};

/**
 * @brief Gets the local history.
 * @author Hamid Zargar
 */

std::vector<Trade> TradingStrategy::getLocalHistory(){
    return this->local_history;
};

/**
 * @brief Creates a trade object.
 * @author Hamid Zargar
 * @return A Trade object that will be executed
 */

Trade TradingStrategy::createTrade(int num_shares, int action){

    Trade trade(this->ticker, num_shares, action, price_fetcher.fetch_last_price(this->ticker, 0), this->strategy_id);        //open a new position
    return trade;
}

/**
 * @brief Gets the strategy id of the strategy.
 * @author Hamid Zargar
 * @return The strategy id
 */

int TradingStrategy::getStrategyID(){
    return this->strategy_id;
}

/**
 * @brief Gets the ticker the strategy is executing on.
 * @author Hamid Zargar
 * @return The ticker
 */

std::string TradingStrategy::getTicker() {
    return this->ticker;
}

/**
 * @brief Destructor to deallocate memory.
 * @author Hamid Zargar
 */

TradingStrategy::~TradingStrategy() = default;

