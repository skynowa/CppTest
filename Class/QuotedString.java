/**
Notice the benefits I gained:
The object is lazy — it doesn’t perform any calculations if not needed.
It is easy to test.
It is small, so it is easy to maintain in the future.
It is easy to use in collections. You can wrap multiple items in a collection with the object, but in the end use just a few of them. This way you will not perform heavy calculations on the entire collection if not needed.
It is immutable.
It is cheap to create. Java is designed to create new objects.
*/

/**
 * Put quotes around the given String if necessary.
 * <p>
 * If the argument doesn't include spaces or quotes, return it as is. If it
 * contains double quotes, use single quotes - else surround the argument by
 * double quotes.
 * </p>
 * <p>
 * Copied from Apache Commons Exec: http://commons.apache.org/proper/commons-exec/
 */
class QuotedString
{
    private static final String SINGLE_QUOTE = "\'";
    private static final String DOUBLE_QUOTE = "\"";

    private final String argument;

    public QuotedString(String argument)
	{
        this.argument = argument;
    }

    public String toString()
	{
        String cleanedArgument = argument.trim();

        // strip the quotes from both ends
        while (cleanedArgument.startsWith(SINGLE_QUOTE) ||
               cleanedArgument.startsWith(DOUBLE_QUOTE))
        {
            cleanedArgument = cleanedArgument.substring(1);
        }

        while (cleanedArgument.endsWith(SINGLE_QUOTE) ||
               cleanedArgument.endsWith(DOUBLE_QUOTE))
        {
            cleanedArgument = cleanedArgument.substring(0, cleanedArgument.length() - 1);
        }

        final StringBuilder buf = new StringBuilder();

        if (cleanedArgument.contains(DOUBLE_QUOTE)) {
            if (cleanedArgument.contains(SINGLE_QUOTE)) {
                throw new IllegalArgumentException("Can't handle single and double quotes in same argument");
            }

            return buf.append(SINGLE_QUOTE).append(cleanedArgument).append(
                SINGLE_QUOTE).toString();
        }
		else if (cleanedArgument.contains(SINGLE_QUOTE) ||
                 cleanedArgument.contains(" "))
        {
            return buf
                .append(DOUBLE_QUOTE)
                .append(cleanedArgument)
                .append(DOUBLE_QUOTE)
                .toString();
        }
		else {
            return cleanedArgument;
        }
    }
}