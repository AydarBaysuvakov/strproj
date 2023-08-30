#ifndef __COLOUR_H__
#define __COLOUR_H__

/// @brief Коды цветов для ColoredPrintf().
enum Colour
    {
    BLACK   = 30, //!< Черный.
    RED     = 31, //!< Красный.
    GREEN   = 32, //!< Зеленый.
    YELLOW  = 33, //!< Желтый.
    BLUE    = 34, //!< Синий.
    MAGENTA = 35, //!< Пурпурный.
    CYAN    = 36, //!< Голубой.
    RESET   = 0   //!< Сброс.
    };

/// @brief Печатает цветной текст.
/// @param colour Цвет.
/// @param format Формат вывода.
/// @param  Параметры для вывода.
void ColouredPrintf(Colour colour, const char* format, ...);
#endif // __COLOUR_H__
