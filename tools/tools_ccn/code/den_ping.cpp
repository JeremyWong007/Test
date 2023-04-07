void mcp::den::handle_den_mining_ping(const mcp::den_mining_ping &ping, const dev::Address &addr, const uint32_t &time, mcp::db::db_transaction & transaction_a, mcp::block_store &store)
{
    if(m_dens.count(addr) == 0) return;
    auto &u = m_dens[addr];
    auto &pings = m_dens[addr].pings;
    uint32_t day = time / (3600 * 24);
    uint32_t hour = time / 3600 % 24 + 1;
    pings[day][hour] = {ping.mci, ping.hash, time, true};
    uint64_t last_stable_mci = store.last_stable_mci_get(transaction_a);
    for(uint32_t h=m_block_time[u.last_ping_mci].time/3600+1; h<time/3600; h++){
        uint64_t mci = u.last_ping_mci + u.ping_interval;
        uint32_t h_time = h * 3600;
        std::map<uint32_t, block_time>::iterator it = m_block_time.find(mci);
        if(it->second.time == h_time){
            //if need ping
        }
        else if(it->second.time < h_time){
            for(;it!=m_block_time.end() ;it++){
                if(it->second.time > h_time){
                    
                    //if need ping
                    break;
                }
            }
        }
        else
        {
            auto hs = (it->second.time - h_time)/3600;
            for(; ;it--){
                if(it->second.time < h_time+hs*3600){
                    
                    //if need ping
                    if(hs == 0) break;
                    else{
                        hs--;
                    }
                }
            }
        }
    }
}