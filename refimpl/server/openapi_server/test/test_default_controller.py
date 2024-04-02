import unittest

from flask import json

from openapi_server.models.error import Error  # noqa: E501
from openapi_server.models.fronter import Fronter  # noqa: E501
from openapi_server.models.member import Member  # noqa: E501
from openapi_server.models.partial_member import PartialMember  # noqa: E501
from openapi_server.models.partial_system import PartialSystem  # noqa: E501
from openapi_server.models.pronoun import Pronoun  # noqa: E501
from openapi_server.models.system import System  # noqa: E501
from openapi_server.test import BaseTestCase


class TestDefaultController(BaseTestCase):
    """DefaultController integration test stubs"""

    def test_system_post(self):
        """Test case for system_post

        Create a new plural system
        """
        partial_system = openapi_server.PartialSystem()
        headers = { 
            'Accept': 'application/json',
            'Content-Type': 'application/json',
            'Authorization': 'Bearer special-key',
        }
        response = self.client.open(
            '/system',
            method='POST',
            headers=headers,
            data=json.dumps(partial_system),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_fronters_get(self):
        """Test case for system_system_fronters_get

        Retrieves the current fronters' API paths
        """
        headers = { 
            'Accept': 'application/json',
        }
        response = self.client.open(
            '/system/{system}/fronters'.format(system='system_example'),
            method='GET',
            headers=headers)
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_fronters_put(self):
        """Test case for system_system_fronters_put

        Set the fronter of a plural system
        """
        request_body = ['request_body_example']
        headers = { 
            'Accept': 'application/json',
            'Content-Type': 'application/json',
        }
        response = self.client.open(
            '/system/{system}/fronters'.format(system='system_example'),
            method='PUT',
            headers=headers,
            data=json.dumps(request_body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_get(self):
        """Test case for system_system_get

        Get plural system information
        """
        headers = { 
            'Accept': 'application/json',
        }
        response = self.client.open(
            '/system/{system}'.format(system='system_example'),
            method='GET',
            headers=headers)
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_member_member_get(self):
        """Test case for system_system_member_member_get

        Get member information
        """
        headers = { 
            'Accept': 'application/json',
        }
        response = self.client.open(
            '/system/{system}/member/{member}'.format(system='system_example', member='member_example'),
            method='GET',
            headers=headers)
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_member_member_pronouns_get(self):
        """Test case for system_system_member_member_pronouns_get

        Get member pronouns
        """
        headers = { 
            'Accept': 'application/json',
            'Authorization': 'Bearer special-key',
        }
        response = self.client.open(
            '/system/{system}/member/{member}/pronouns'.format(system='system_example', member='member_example'),
            method='GET',
            headers=headers)
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_system_system_members_post(self):
        """Test case for system_system_members_post

        Add a new member to a plural system
        """
        partial_member = openapi_server.PartialMember()
        headers = { 
            'Accept': 'application/json',
            'Content-Type': 'application/json',
        }
        response = self.client.open(
            '/system/{system}/members'.format(system='system_example'),
            method='POST',
            headers=headers,
            data=json.dumps(partial_member),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    unittest.main()
