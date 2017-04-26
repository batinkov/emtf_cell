#ifndef __Mtf7_CONFIG_COMMANDS_HPP__
#define __Mtf7_CONFIG_COMMANDS_HPP__

#include "swatch/core/Command.hpp"

namespace emtf {

class CheckFWVersion : public swatch::core::Command
{
public:
    CheckFWVersion(const std::string& aId, swatch::core::ActionableObject& aActionable);

    virtual swatch::core::Command::State code(const swatch::core::XParameterSet& params);
};

} // namespace

#endif /* __Mtf7_CONFIG_COMMANDS_HPP__ */
