
from mod_python import apache
markdown = apache.import_module('__init__')

import sys

## Import
def importETree():
    """Import the best implementation of ElementTree, return a module object."""
    etree_in_c = None
    try: # Is it Python 2.5+ with C implemenation of ElementTree installed?
        import xml.etree.cElementTree as etree_in_c
    except ImportError:
        try: # Is it Python 2.5+ with Python implementation of ElementTree?
            import xml.etree.ElementTree as etree
        except ImportError:
            try: # An earlier version of Python with cElementTree installed?
                import cElementTree as etree_in_c
            except ImportError:
                try: # An earlier version of Python with Python ElementTree?
                    import elementtree.ElementTree as etree
                except ImportError:
                    markdown.message(markdown.CRITICAL, "Failed to import ElementTree")
                    sys.exit(1)
    if etree_in_c and etree_in_c.VERSION < "1.0":
        markdown.message(markdown.CRITICAL, "For cElementTree version 1.0 or higher is required.")
        sys.exit(1)
    elif etree_in_c :
        return etree_in_c
    elif etree.VERSION < "1.1":
        markdown.message(markdown.CRITICAL, "For ElementTree version 1.1 or higher is required")
        sys.exit(1)
    else :
        return etree

