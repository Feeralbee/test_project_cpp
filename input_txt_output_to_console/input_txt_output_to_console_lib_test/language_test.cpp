#include "gtest/gtest.h"
#include "language.h"

TEST(interface_language, language_selection)
{
	ASSERT_EQ(interface_language_selection("yes"), language::russian);
	ASSERT_EQ(interface_language_selection("no"), language::english);
	ASSERT_EQ(interface_language_selection(" "), language::unknown);
}