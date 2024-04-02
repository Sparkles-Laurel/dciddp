import connexion
from typing import Dict
from typing import Tuple
from typing import Union

from openapi_server.models.error import Error  # noqa: E501
from openapi_server.models.fronter import Fronter  # noqa: E501
from openapi_server.models.member import Member  # noqa: E501
from openapi_server.models.partial_member import PartialMember  # noqa: E501
from openapi_server.models.partial_system import PartialSystem  # noqa: E501
from openapi_server.models.pronoun import Pronoun  # noqa: E501
from openapi_server.models.system import System  # noqa: E501
from openapi_server import util


def system_post(partial_system):  # noqa: E501
    """Create a new plural system

    Create a new plural system with the specified name and pronouns # noqa: E501

    :param partial_system: 
    :type partial_system: dict | bytes

    :rtype: Union[System, Tuple[System, int], Tuple[System, int, Dict[str, str]]
    """
    if connexion.request.is_json:
        partial_system = PartialSystem.from_dict(connexion.request.get_json())  # noqa: E501
    return 'do some magic!'


def system_system_fronters_get(system):  # noqa: E501
    """Retrieves the current fronters&#39; API paths

    Retrieves the list of the current fronter(s) # noqa: E501

    :param system: The ID of the system
    :type system: str

    :rtype: Union[List[Fronter], Tuple[List[Fronter], int], Tuple[List[Fronter], int, Dict[str, str]]
    """
    return 'do some magic!'


def system_system_fronters_put(system, request_body):  # noqa: E501
    """Set the fronter of a plural system

    Set the fronter of a plural system to the specified member # noqa: E501

    :param system: The ID of the system
    :type system: str
    :param request_body: 
    :type request_body: List[str]

    :rtype: Union[None, Tuple[None, int], Tuple[None, int, Dict[str, str]]
    """
    return 'do some magic!'


def system_system_get(system):  # noqa: E501
    """Get plural system information

    Retrieve information about a plural system # noqa: E501

    :param system: The ID of the system
    :type system: str

    :rtype: Union[System, Tuple[System, int], Tuple[System, int, Dict[str, str]]
    """
    return 'do some magic!'


def system_system_member_member_get(system, member):  # noqa: E501
    """Get member information

    Retrieve information about a member of a plural system # noqa: E501

    :param system: The ID of the system
    :type system: str
    :param member: The ID of the member
    :type member: str

    :rtype: Union[Member, Tuple[Member, int], Tuple[Member, int, Dict[str, str]]
    """
    return 'do some magic!'


def system_system_member_member_pronouns_get(system, member):  # noqa: E501
    """Get member pronouns

    Retrieve pronouns of a member of a plural system # noqa: E501

    :param system: The ID of the system
    :type system: str
    :param member: The ID of the member
    :type member: str

    :rtype: Union[List[Pronoun], Tuple[List[Pronoun], int], Tuple[List[Pronoun], int, Dict[str, str]]
    """
    return 'do some magic!'


def system_system_members_post(system, partial_member):  # noqa: E501
    """Add a new member to a plural system

    Add a new member to a plural system with the specified name and pronouns # noqa: E501

    :param system: The ID of the system
    :type system: str
    :param partial_member: 
    :type partial_member: dict | bytes

    :rtype: Union[Member, Tuple[Member, int], Tuple[Member, int, Dict[str, str]]
    """
    if connexion.request.is_json:
        partial_member = PartialMember.from_dict(connexion.request.get_json())  # noqa: E501
    return 'do some magic!'
