#include <array>
#include <string>
#include <string_view>
#include <optional>

#include <../3rdparty/magic_enum/include/magic_enum.hpp>

template<class Enum, class S = std::string_view>
class MapByEnum
{
    static_assert(std::is_enum_v<Enum>, "No enum");

public:
    constexpr S operator [](Enum n)
    {
        return mArr[static_cast<int>(n)];
    }

    constexpr S at(Enum n)
    {
        return mArr[static_cast<int>(n)];
    }

    constexpr std::optional<Enum> index(S value)
    {
        auto it = std::find(std::cbegin(mArr), std::cend(mArr), value);

        if(it == std::cend(mArr))
            return std::nullopt;

        return Enum(std::distance(std::cbegin(mArr), it));
    }

private:
    static constexpr std::array mArr = []() constexpr {
        constexpr auto names = magic_enum::enum_names<Enum>();
        std::array<S, names.size()> arr;

        for (int i = 0; i < names.size(); ++i)
            arr[i] = names[i];

        return arr;
    }();
};
