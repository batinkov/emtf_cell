#ifndef __EMTF_CSC_PORT_IDS_HPP__
#define __EMTF_CSC_PORT_IDS_HPP__

#include <map>
#include <string>
#include <sstream>

namespace emtf {

class EmtfCscInputPortIds
{
public:
    static uint64_t getId(const uint32_t endcap, const uint32_t sector, std::string id)
    {
        std::stringstream mapId;
        mapId << endcap << "_" << sector << "_" << id;

        return ids.at(mapId.str());
    }

private:
    // the class in not a Singleton but because only the static 'getId' function is supposed to be used hide the
    // constructor, the copy-constructor, the assignment operator and the destructor
    EmtfCscInputPortIds();
    EmtfCscInputPortIds(const EmtfCscInputPortIds &init);
    EmtfCscInputPortIds & operator=(const EmtfCscInputPortIds &init);
    ~EmtfCscInputPortIds();

    static const std::map<std::string, uint64_t> ids;
};

} // namespace

#endif /* __EMTF_CSC_PORT_IDS_HPP__ */

