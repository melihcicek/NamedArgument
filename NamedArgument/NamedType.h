#pragma once


template<typename T, typename Tag>
class NamedType {
public:
    NamedType() = default;
    NamedType(T&& val) : m_val{ std::move(val) } {}
    NamedType(const T& val) : m_val{ val } {}
    T& get() { return m_val; }
    const T& get()const { return m_val; }
private:
    T m_val{};
};
